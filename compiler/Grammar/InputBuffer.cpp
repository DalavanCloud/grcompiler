/**
 * <b>SOFTWARE RIGHTS</b>
 * <p>
 * ANTLR 2.6.0 MageLang Insitute, 1998
 * <p>
 * We reserve no legal rights to the ANTLR--it is fully in the
 * public domain. An individual or company may do whatever
 * they wish with source code distributed with ANTLR or the
 * code generated by ANTLR, including the incorporation of
 * ANTLR, or its output, into commerical software.
 * <p>
 * We encourage users to develop software with ANTLR. However,
 * we do ask that credit is given to us for developing
 * ANTLR. By "credit", we mean that if you use ANTLR or
 * incorporate any source code into one of your programs
 * (commercial product, research project, or otherwise) that
 * you acknowledge this fact somewhere in the documentation,
 * research report, etc... If you like ANTLR and have
 * developed a nice tool with the output, please mention that
 * you developed it using ANTLR. In addition, we ask that the
 * headers remain intact in our source code. As long as these
 * guidelines are kept, we expect to continue enhancing this
 * system and expect to make other tools available as they are
 * completed.
 * <p>
 * The ANTLR gang:
 * @version ANTLR 2.6.0 MageLang Insitute, 1998
 * @author Terence Parr, <a href=http://www.MageLang.com>MageLang Institute</a>
 * @author <br>John Lilley, <a href=http://www.Empathy.com>Empathy Software</a>
 * @author <br><a href="mailto:pete@yamuna.demon.co.uk">Pete Wells</a>
 */

/**A Stream of characters fed to the lexer from a InputStream that can
 * be rewound via mark()/rewind() methods.
 * <p>
 * A dynamic array is used to buffer up all the input characters.  Normally,
 * "k" characters are stored in the buffer.  More characters may be stored during
 * guess mode (testing syntactic predicate), or when LT(i>k) is referenced.
 * Consumption of characters is deferred.  In other words, reading the next
 * character is not done by conume(), but deferred until needed by LA or LT.
 * <p>
 *
 * @see antlr.CharQueue
 */

#include "Antlr/InputBuffer.hpp"
//#include <cstring>

/** Create a character buffer */
InputBuffer::InputBuffer()
: nMarkers(0), markerOffset(0), numToConsume(0)
{}

/** This method updates the state of the input buffer so that
 *  the text matched since the most recent mark() is no longer
 *  held by the buffer.  So, you either do a mark/rewind for
 *  failed predicate or mark/commit to keep on parsing without
 *  rewinding the input.
 */
void InputBuffer::commit()
{
	nMarkers--;
}

/** Mark another character for deferred consumption */
void InputBuffer::consume()
{
	numToConsume++;
}

/** Ensure that the character buffer is sufficiently full */
void InputBuffer::fill(int amount)
{
	syncConsume();
	// Fill the buffer sufficiently to hold needed characters
	while (queue.entries() < amount + markerOffset) {
		// Append the next character
		queue.append(getChar());
	}
}

bool InputBuffer::isMarked() const
{
	return (nMarkers != 0);
}

/** Get a lookahead character */
int InputBuffer::LA(int i)
{
	fill(i);
	return queue.elementAt(markerOffset + i - 1);
}

/**Return an integer marker that can be used to rewind the buffer to
 * its current state.
 */
int InputBuffer::mark()
{
	syncConsume();
	nMarkers++;
	return markerOffset;
}

/**Rewind the character buffer to a marker.
 * @param mark Marker returned previously from mark()
 */
void InputBuffer::rewind(int mark)
{
	syncConsume();
	markerOffset = mark;
	nMarkers--;
}

/** Sync up deferred consumption */
void InputBuffer::syncConsume() {
	while (numToConsume > 0) {
		if (nMarkers > 0)
		{
			// guess mode -- leave leading characters and bump offset.
			markerOffset++;
		} else {
			// normal mode -- remove first character
			queue.removeFirst();
		}
		numToConsume--;
	}
}

