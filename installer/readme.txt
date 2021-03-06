FILES INCLUDED

Program Files
* GrCompiler.exe - Graphite compiler version 5.0
* icuuc56.dll - ICU character definitions that are used to initialize certain glyph attributes based on the correspnding Unicode character properties.
* icudt56.dll - ICU data tables
* gdlpp.exe - preprocessor to handle #define and #include statements
* stddef.gdh - standard GDL abbreviations

For testing the installation ("example" folder)
* allcaps.gdl - simple GDL program
* stddr.ttf - simple Roman font to compile with allcaps.gdl
* makecaps.wpx - WorldPad file to use to test the result

Documentation files ("doc" folder)
* GraphiteOverview.pdf
* GDL.pdf
* CompilerDebugFiles.pdf
* StackMachineCommands.pdf
* TransductionLog.pdf
* GTF_4_0.pdf
* GDL_BNF.pdf
* CppDoc.pdf


INSTALLING THE PROGRAM

After running the installer program, all the program files will be located in the indicated folder. The Path environment variable will be modified to include the directory containing grcompiler.exe.

If you choose to put the gdlpp.exe file in a different folder from GrCompiler.exe, you need to set the GDLPP environment variable to indicate where this utility is, for instance: "c:\graphite_extras\gdlpp.exe". Note that the variable must include the name of the program as well as well as the path.

The GDLPP_PREFS environment variable is used to indicate where the Graphite compiler will find #included files. The value consists of "-I" followed by the path or paths to files of interest, for instance, "-Ic:\graphite". At the very least, you will want to be able to #include "stddef.gdh", which is the standard include file that contains all the standard GDL abbrevations. If it is located in a different folder than the GDL source code and font file, you will need to put its path in the GDLPP_PREFS environment variable. The installer will initialize GDLPP_PREFS to point to the directory containing this file, which will be in the same directory as grcompiler.exe.

NOTE: GDLPP_PREFS must not contain directory names with spaces. If there are spaces in your path, you will need to use 8-character directory names. So if, for instance, your "stddef.gdh" file is located in C:\Program Files\Graphite Compiler, GDLPP_PREFS should be set to "-IC:\Progra~1\Graphi~1" (without quotes). If the compiler is having trouble finding the stddef.gdh file (ie, standard definitions are not recognized), check your GDLPP_PREFS environment variable and change it to use short names if necessary.


RUNNING THE COMPILER

To run the compiler, execute the grcompiler.exe file. Omitting all arguments will give a summary of the expected syntax, which is:

      grcompiler [options] gdl-file input-font-file [output-font-file] [output-font-name]

If the output-font-file argument is omitted, the name of the resulting Graphite-enabled font file will be the same as the input-font-file with "_gr" appended. For instance, if your input-font-file is "myfont.ttf", the output file will be "myfont_gr.ttf".

If the output-font-name is omitted, the resulting font will have the same name as the original font.

Options:

-c - generate a compressed version of the font

-d - causes the compiler to output the XML debugger file. This flag is recommended, and required for fonts to run in Graide.

-D - causes the compiler to output both the XML file and the text debugger files. The text files are documented in "Compiler Debug Files.doc".

-g - permit and ignore invalid glyph definitions.

-q - runs in quiet mode, generating no messages unless there is an error.

-nNNNN - allows specifying of the location of the name table start location.

-vN - allows you to specify the version of the font tables to be generated; e.g., "-v3". Version 2 will be generated by default.

-wNNNN - ignore warning with the given number.

-wall - show all warnings (warnings can be hidden by adding subsequent -wNNNN options).


TESTING THE INSTALLATION

The file "allcaps.gdl" is a very simple program that you can try to compile. It needs to be compiled with a font that contains the Roman alphabet--a, b, c, etc. The stddr.ttf is such a font and is included as part of the installation. These files are located in the example folder.


UNINSTALLING THE PROGRAM

To uninstall, run "unins000.exe".


CHANGES SINCE VERSION 4.3.1

* Upgrade to use ICU 5.6.

* Added support for automatic collision fixing.

* Added support for table compression.

* Replaced bidi pass (between substitution and positioning passes) with Direction setting on any pass.

* Automatically create associations for insertion and deletion rules for multi-slot rules (previously this only worked for rules with two slots).

* Support glyph.<attrName> syntax in rules to force reading of a glyph attribute rather than a slot attribute.

* Support setting features in rules.

* Support bit-wise operators and special SetBits operator.


CHANGES SINCE VERSION 4.3

* Upgrade to use ICU 4.9.

* Support bidirectional bracket and isolate codes.

* Added built-in *skipPasses* glyph attribute to allow Graphite2 to optimize by avoiding passes based on the glyphs in the stream.


CHANGES SINCE VERSION 4.2

* Operators &= and -= are now handled for class definitions.

* Permit multiple justification levels.


CHANGES SINCE VERSION 4.1

* Allow a font with Graphite tables to serve as input.

* Changed -d option to -D, -d option now generates XML file only.

* Output decimal numbers for glyph IDs in debugger files.

* Handle a large number of glyphs in replacement classes; this will produce Silf table v 4.0.

* Ensure that requesting the metrics of a pseudo-glyph will return the metrics of the corresponding actual glyph.

* Error messages and debugger files use decimal for glyph IDs.

* Add the segsplit slot attribute, to be used by the Graphite2 engine for caching optimization.

* Added a line-break flag to permit optimization in Graphite2.

* Fixed problems with Macintosh strings in the name table.


CHANGES SINCE VERSION 2.4

* Support pass constraints.

* Handles the mirror.glyph and mirror.isEncoded glyph attributes. (These are only supported in the Graphite2 engine.)

* Outputs a .GDX file to be used by the Graphite2 debugger.

* Automatically creates associations for insertions and deletions when they are unambiguous.

* Improved pretty-print output for rules.

* Support version 2.0 of the Glat table which allows more than 256 glyph attributes.


CHANGES SINCE VERSION 2.3

* The Bidi global now defaults to false, except when the font supports multiple directions.

* Now uses ICU to find default breakweight and directionality values.

* Added the -g option to permit (ignore) undefined glyphs.

* Added the -w option to allow turning off warnings.

* Added the -q option: quiet mode.

* Fixed long-standing problem with name table output: should now correctly output any relevant platforms and encodings.

* Gives a warning if horizontally overlapping glyphs are not attached (this warning can be ignored using the -w switch: -w3521.


CHANGES SINCE VERSION 1.9:

* The argument syntax and a list of available switches will be displayed when the program is invoked at a command line without arguments.

* As of version 2.3, it is capable of generating version 3.0 of the font tables. However, version 2.0 will be generated by default.

* Version 2.3 introduced the capacity for the GDL language table and 'Sill' font table.

* The maximum number of features was increased to 64.

* A warning is given if a rule includes horizontally overlapping glyphs that are not positioned using attachments.


CHANGES SINCE VERSION 1.1:

* Version 1.9 handles a more recent version of the OS/2 generated by Font Lab 5.0. This bug showed up as error code #26 when running the Graphite compiler.

* Version 1.9 will not initialize the directionality and breakweight glyph attributes from a Unicode database. A warning to this effect is put in the gdlerr.txt file.

* Support for justification has been added.


CHANGES SINCE VERSION 1.0:

* It is now possible use U+... syntax to identify a glyph by Unicode codepoint. For instance, the following are equivalent:

    U+1234             =   unicode(0x1234)
    (U+0303..U+03FF)   =   unicode(0x0303..03FF)

* Version 1.1 includes the ability to work with fonts that include Unicode supplementary plane characters (characters greater than U+FFFF). However, version 2 of the font tables must be output in order to handle this feature. If you are working with a font that includes supplementary plane characters, you must include "/v2" in your command line to generate version 2 of the tables, for instance:

    grcompiler /d /v2 myprog.gdl myfont.ttf

You must also have WorldPad version 1.5 in order to read version 2 of the font tables.

* The compiler will no longer give bogus warnings about directionality when you have a setting of Bidi=false in your GDL program.



KNOWN BUGS AND INFELICITIES

The following are known bugs and unexpected behaviors in the Graphite compiler:

* Using "bb" as part of a glyph name can be problematic, because the #include mechanism replaces it with "boundingbox". Workaround: for Unicode values, use BB instead.

* Postscript names: some problems have been reported with the handling of Postscript names by the compiler. The development team is unsure as to the extent of the problem.

* The Graphite compiler may occasionally give spurious warnings about inconsistent or inappropriate glyph attribute types. These may usually be safely ignored.

* There is an obscure bug with embedded tables and passes. Workaround: avoid embedding passes in other passes.

* If you try to compile a GDL program that does not exist, you may get a very unhelpful error message.
