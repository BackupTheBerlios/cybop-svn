%
% $RCSfile: tuxtax.cls,v $
%
% Copyright (c) 2002-2007. Christian Heller. All rights reserved.
%
% Permission is granted to copy, distribute and/or modify this document
% under the terms of the GNU Free Documentation License, Version 1.1 or
% any later version published by the Free Software Foundation; with no
% Invariant Sections, with no Front-Cover Texts and with no Back-Cover
% Texts. A copy of the license is included in the section entitled
% "GNU Free Documentation License".
%
% http://www.tuxtax.de
% - Software Wisdom is our Passion -
%
% http://www.cybop.net
% - Cybernetics Oriented Programming -
%
% http://www.resmedicinae.org
% - Information in Medicine -
%
% Version: $Revision: 1.1 $ $Date: 2007-07-17 20:02:36 $ $Author: christian $
% Authors: Christian Heller <christian.heller@tuxtax.de>
%

%
% Require LaTeX2e version and do NOT base on older versions like 2.09!
%
\NeedsTeXFormat{LaTeX2e}

%
% Define class name.
%
% CAUTION! Do not use 2005-10-27 format, since the "-" lead to an error!
%
\ProvidesClass{tuxtax}[2006/01/02 v1.0
^^J LaTeX document class for Books published by Tux Tax]

%
% Prints out a copyright notice during compilation.
%
\typeout{Copyright (c) 2002-2007. Christian Heller. All rights reserved.}
\typeout{Permission is granted to copy, distribute and/or modify this document
under the terms of the GNU Free Documentation License, Version 1.1 or
any later version published by the Free Software Foundation; with no
Invariant Sections, with no Front-Cover Texts and with no Back-Cover
Texts. A copy of the license is included in the section entitled
"GNU Free Documentation License".}
\typeout{http://www.tuxtax.de}

%
% Define base class.
%
% By default, the scrreprt class uses the following options:
% titlepage: starts a new page after the document title
% twoside: generates double sided output
% openright: makes chapters begin only on right hand pages
%
\newcommand{\@BaseClass}{scrreprt}

\newif\if@kapitel

%
% Declare options that can be handed over with the \documentclass command.
% Pass them on to the base class.
%
%\DeclareOption{b5paper}{\PassOptionsToClass{\CurrentOption}{\@BaseClass}}
\DeclareOption{9pt}{\PassOptionsToClass{\CurrentOption,DIV9}{\@BaseClass}}
%\DeclareOption{9.5pt}{\PassOptionsToClass{\CurrentOption,DIV9}{\@BaseClass}}
%\DeclareOption{11pt}{\PassOptionsToClass{\CurrentOption,DIV12}{\@BaseClass}}
%\DeclareOption{12pt}{\PassOptionsToClass{\CurrentOption,DIV14}{\@BaseClass}}
\DeclareOption{oneside}{\@twosidefalse}
\DeclareOption{twoside}{\@twosidetrue}
\DeclareOption{openright}{\PassOptionsToClass{\CurrentOption}{\@BaseClass}}
\DeclareOption{openany}{\PassOptionsToClass{\CurrentOption}{\@BaseClass}}
%\DeclareOption{kapitel}{\@kapiteltrue}
%\DeclareOption{nokapitel}{\@kapitelfalse}

%
% Pass side option to base class.
%
\if@twoside
    \PassOptionsToClass{twoside}{\@BaseClass}
\else
    \PassOptionsToClass{oneside}{\@BaseClass}
\fi

%
% Execute options.
%
%\ExecuteOptions{11pt,oneside,kapitel}

%
% Process options.
%
% This command is necessary to finish the options section.
% If missing, latex will assume it is still in the options section
% and throw an error when reaching the \LoadClass command.
%
\ProcessOptions

%
% Load base class.
%
% \LoadClass is the equivalent of \RequirePackage.
%
\LoadClass[headsepline,BCOR10mm]{\@BaseClass}

%
% Use geometry package to customise page layout.
%
% CAUTION! This package HAS TO BE INSERTED BEFORE the fancyhdr package!
% Otherwise, text is formatted correctly, but headers and footers are not.
%
% Possible options with example values:
% paperwidth=16.8cm
% paperheight=24cm
% width=16cm
% height=23cm
% twoside
% bindingoffset=-2cm
% inner=3cm
% outer=2cm
% top=2cm
% bottom=2cm
% includeheadfoot
% includemp
%
% Examples:
% \usepackage[paperwidth=19cm,paperheight=26cm]{geometry}
% \usepackage[b5paper,twoside]{geometry}
%
\usepackage[paperwidth=17cm,paperheight=24cm]{geometry}

%
% Use hyperref package for clickable links and bookmark support in pdf files.
%
% CAUTION! For some strange reason, paperwidth and paperheight only work with
% package "hyperref". It seems more proper to use the "geometry" package then.
%
%\usepackage{hyperref}

%
% The classical space settings for edges (left, top, right, bottom).
%
% The left margin is determined by oddsidemargin and evensidemargin, respectively.
%
% CAUTION! For some strange reason, paperwidth and paperheight only work with
% package "hyperref". It seems more proper to use the "geometry" package then.
%
%\setlength{\paperwidth}{19cm}
%\setlength{\paperheight}{26cm}
%\setlength{\hoffset}{-3cm}
%\setlength{\voffset}{-2.7cm}
%\setlength{\oddsidemargin}{3cm}
%\setlength{\evensidemargin}{3cm}
%\setlength{\topmargin}{2cm}
%\setlength{\textwidth}{15.7cm}
%\setlength{\textheight}{23cm}

%
% Use page layout with sophisticated control of page headers,
% footers, page style, floats.
%
% Package location in Debian GNU/Linux: /usr/share/texmf/tex/latex/fancyhdr
%
% CAUTION! This package HAS TO BE INSERTED AFTER the geometry package!
% Otherwise, text is formatted correctly, but headers and footers are not.
%
\usepackage[]{fancyhdr}

%
% Use indexing.
%
% Contains commands: \makeindex, \printindex
%
\usepackage{makeidx}

%
% Add document elements like a bibliography or an index to the table of contents.
%
% Options:
% - nottoc: disables the inclusion of the table of contents (toc)
% - chapter: use chapter-level headings, if possible
% - section: use section-level headings, if possible
% - numbib: number the bibliography heading (default is no number)
% - numindex: number the index heading (default is no number)
%
% If the chapter or section options are used to select the appropriate style,
% the class MUST DEFINE \chapter* and \@makeschapterhead or \section*, respectively!
%
% This package uses \tocbibname to store the name of the bibliography.
%
% The following commands set the heading texts:
% - of the index: \setindexname
% - of the table of contents (toc): \settocname
% - of the list of tables (lot): \setlotname
% - of the list of figures (lof): \setlofname
% - of the bibliography: \settocbibname
%
% When used with standard classes, the heading text is picked up from:
% \indexname, \contentsname, \listtablename, \listfigurename.
% These are changed when using the commands listed above.
% Thus, the following two lines of code have the same effect:
%
% - classical version: \renewcommand{\listfigurename}{Figures}
% - tocbibind version: \setlofname{Figures}
%
% Contains commands: \setindexname, \settocname, \setlotname, \setlofname, \settocbibname
%
\usepackage[section,nottoc,numbib,numindex]{tocbibind}

%
% Use graphics.
%
% Contains commands: \includegraphics
%
\usepackage{graphicx}

%
% Float text around figures.
%
% This is needed for the figures at the beginning of chapters
% Statics & Dynamics, Knowledge Schema, State & Logic.
%
% Example:
% \begin{wrapfigure}[n Zeilen(z.B: 16)]{l oder r}{Feldbreite(z.B: 5cm)}
%     \includegraphics[width= Bildbreite ]{ Name der Bilddatei }
%     \caption{ Bildunterschrift }
%     \label{ marke }
% \end{wrapfigure}
%
\usepackage{wrapfig}

%
% Insert pictures into paragraphs.
%
%\usepackage[]{picins}

%
% Colourful graphics.
%
% CAUTION! Works only when translating to Postscript, since it uses its commands.
%
%\usepackage[]{pstricks}

%
% Use ??
%
%\usepackage{psfrag}

%
% Use font.
%
%\usepackage{times}

%
% Use german umlauts ä, ö, ü, ß.
%
% CAUTION! "Part" will be changed into "Teil", "Chapter" into "Kapitel" etc.!
%
% One can also use umlauts WITHOUT this package,
% such as in english publications, by typing:
% \"a \"A \"o \"O \"u \"U \ss{}
%
%\usepackage{ngerman}
%\usepackage{german}

%
% Use german formatting for references (sources of literature).
%
%\usepackage{bibgerm}

%
% Modify any subsequent \chapter commands so that the result looks like
% that of \chapter* (a chapter title without the prefix string "Chapter")
% except that the chapter number is put on the same line as the title.
%
% Required package: tocbibind
%
%\simplechapter

%
% Activate numbered headings for the list of figures (lof),
% the list of tables (lot) etc.
%
% Modify the internally used \toc@section for typesetting
% the list of headings in non-chaptered documents.
% The \tocsection command modifies \toc@section to typeset
% using \section (with numbering) instead of \section*.
%
% The \begingroup \endgroup pairing keeps the changes local.
%
% Required package: tocbibind
%
%\renewcommand{\listoffigures}{\begingroup
%    \tocsection
%    \tocfile{\listfigurename}{lof}
%\endgroup}

%\renewcommand{\listoftables}{\begingroup
%    \tocsection
%    \tocfile{\listtablename}{lot}
%\endgroup}

%
% Transform uppercase headers to normalcase.
%
% As these are not normally numbered, it would be a misjudgement to try and
% get a non-existent chapter number into the header.
%
% The command \tocetcmark specifies the marks for ToC, LoF, etc.
% To match the fancy page style, it must be redefined as in the following example:
%
% \pagestyle{fancy}
% \renewcommand{\chaptermark}[1]{\markboth{\thechapter.\ #1}{}}
% \renewcommand{\tocetcmark}[1]{\markboth{#1}{}}
%
% Required package: tocbibind
%

%
% Change headings.
%
\if@kapitel
%    \newcommand{\HeadKap}{Chapter}
    \newcommand{\HeadKap}{}
\else
    \newcommand{\HeadKap}{}
\fi

\newcommand{\HeadKapSep}{.8em}

%
% Set line spacing.
%
% \baselineskip is a length command which specifies the minimum space between
% the bottom of two successive lines in a paragraph. Its value may be
% automatically reset by LaTeX, for example, by font changes in the text.
% The value used for an entire paragraph is the value in effect at the blank
% line or command which ends the paragraph unit.
% The value, of course, depends upon the font size used.
% CAUTION! It should not be changed manually!
%
% \baselinestretch scales the value of \baselineskip.
% Its default value is 1.0 but it may be reset with a \renewcommand command.
% If one wants to change the spacing in a document one should reset
% \baselinestretch and NOT \baselineskip as the latter may be reset
% automatically by LaTeX to account for local variations in the text,
% but it is always scaled by the former.
%
% Approximated values are:
% - simple spacing: \renewcommand{\baselinestretch}{1}
% - one and a half spacing: \renewcommand{\baselinestretch}{1.5}
% - double spacing: \renewcommand{\baselinestretch}{2}
%
\renewcommand{\baselinestretch}{1.5}

%
% Replace:
% \setlength{\parindent}{1em}
% \setlength{\parskip}{1.5ex plus0.5ex minus0.5ex}
% with:
% \RequirePackage{parskip}
%
% parskip defined the distance between two paragraphs.
% parindent defined the indentation of the first line of a paragraph.
%
% \RequirePackage is the equivalent of \LoadClass.
%
\RequirePackage{parskip}

%
% Set footnote formatting.
%
%\renewcommand{\footnoterule}{\rule{5cm}{0.1mm}\vspace{0.3cm}}

%
% The glossary.
%
%\newcommand{\myglossary}[2]{\emph{#1}\glossary{#1}\glossary{#1!#2}}
%\newcommand{\strich}{\begin{center}\rule{10cm}{1.5pt}\end{center}}

%
% Require fancyhdr layout package.
%
% \RequirePackage is the equivalent of \LoadClass.
%
\RequirePackage{fancyhdr}

%
% Set fancy page style.
%
% CAUTION! This must be set first, as it sets the defaults!
%
\pagestyle{fancy}

% Set horizontal decorative line for header.
\renewcommand{\headrulewidth}{0.4pt}
% Set horizontal decorative line for footer.
%\renewcommand{\footrulewidth}{0.4pt}
% Set distance between decorative line in the header
% and the bottom of the header text line.
%\renewcommand{\headruleskip}{2mm}
% Set distance between decorative line in the footer
% and the top of the footer text line.
%\renewcommand{\footruleskip}{2mm}

%
% Redefine the plain page style.
%
% Some LaTeX commands, like \chapter, use the \thispagestyle command to
% automatically switch to the plain page style, thus ignoring the page style
% currently in effect.
% To customise even such pages, the plain page style must be redefined.
%
\fancypagestyle{plain}{%
    % Clear all header and footer fields.
    \fancyhf{}
    % Set left even footer.
%    \fancyhf[lef]{\footnotesize{\textsf{\textsl{\thepage}}}}
    % Set right odd footer.
%    \fancyhf[rof]{\footnotesize{\textsf{\textsl{\thepage}}}}
    \renewcommand{\headrulewidth}{0pt}
    \renewcommand{\footrulewidth}{0pt}
}

% Two sided printing.
\if@twoside

    % The chapter display.
    \renewcommand{\chaptermark}[1]{

        \markboth{\HeadKap~\thechapter\hspace{\HeadKapSep}#1}
        {\HeadKap~\thechapter\hspace{\HeadKapSep}#1}
    }

    % The section display.
    \renewcommand{\sectionmark}[1]{

        \markright{\thesection\hspace{\HeadKapSep}#1}
    }

    %
    % Set headers and footers.
    %
    % CAUTION! Do NOT also set subsection information!
    % Only TWO out of: chapter, section, subsection information can be set!
    %

    % Clear all header and footer fields.
    \fancyhf{}
    % Set left even header.
    \fancyhf[leh]{\footnotesize{\textsf{\textsl{\thepage}}}}
    % Set centre even header.
    %\fancyhf[ceh]{}
    % Set right even header.
    \fancyhf[reh]{\footnotesize{\textsf{\textsl{\leftmark}}}}
    % Set left odd header.
    \fancyhf[loh]{\footnotesize{\textsf{\textsl{\rightmark}}}}
    % Set centre odd header.
    %\fancyhf[coh]{}
    % Set right odd header.
    \fancyhf[roh]{\footnotesize{\textsf{\textsl{\thepage}}}}
    % Set left even footer.
    %\fancyhf[lef]{\footnotesize{\textsf{\textsl{\authormacro}}}}
    % Set centre even footer.
    %\fancyhf[cef]{}
    % Set right even footer.
    %\fancyhf[ref]{\footnotesize{\textsf{\textsl{Inventory number: 2003-12-31/001/INF90/12345}}}}
    % Set left odd footer.
    %\fancyhf[lof]{\footnotesize{\textsf{\textsl{\authormacro}}}}
    % Set centre odd footer.
    %\fancyhf[cof]{}
    % Set right odd footer.
    %\fancyhf[rof]{\footnotesize{\textsf{\textsl{Inventory number: 2003-12-31/001/INF90/12345}}}}

    % See: LaTeX Companion, 4.3!
    \newcommand{\clearemptydoublepage}{\newpage{\pagestyle{empty}\cleardoublepage}}

% One sided printing.
\else

    % The chapter display.
    \renewcommand{\chaptermark}[1]{

        \markboth{\HeadKap~\thechapter\hspace{\HeadKapSep}#1}%
        {\HeadKap~\thechapter\hspace{\HeadKapSep}#1}
    }

    % The section display.
    \renewcommand{\sectionmark}[1]{}

    \lhead[\fancyplain{}{\rightmark}]{\fancyplain{}{\rightmark}}
    \rhead[\fancyplain{}{\thepage}]{\fancyplain{}{\thepage}}
    \cfoot{\fancyplain{\thepage}{}}

    \newcommand{\clearemptydoublepage}{\clearpage}
\fi

%
% Set heading sizes.
%
%\renewcommand{\sectfont}{\bf} %\sffamily\bfseries
\renewcommand{\sectfont}{\sffamily\bfseries}
\newcommand{\chapsize}{\LARGE}
\newcommand{\sectionsize}{\Large}
\newcommand{\subsectionsize}{\large}
\newcommand{\subsubsectionsize}{\normalsize}
\newcommand{\paragraphsize}{\normalsize}
\newcommand{\subparagraphsize}{\normalsize}

%
% Redefine chapter formatting.
%
% This was taken from the scrreprt.cls class file.
%
\renewcommand\chapter{\if@openright\clearemptydoublepage\else\clearpage\fi
                    \thispagestyle{plain}%
                    \global\@topnum\z@
                    \@afterindentfalse
                    \secdef\@chapter\@schapter}

\renewcommand\addchap{\if@openright\clearemptydoublepage\else\clearpage\fi
                    \thispagestyle{plain}%
                    \global\@topnum\z@
                    \@afterindentfalse
                    \secdef\@addchap\@saddchap}

\if@kapitel
    %
    % This was taken from the report.cls class file.
    %
    \def\@makechapterhead#1{%
    \vspace*{50\p@}%
    %
    % The following lines print out "Chapter" before the actual chapter name.
    %
%    {\parindent \z@ \raggedright
%      \ifnum \c@secnumdepth >\m@ne
%        \chapsize \sectfont \@chapapp{} \thechapter
%        \par\nobreak
%        \vskip 0\p@
%      \fi
%      \interlinepenalty\@M
%      \chapsize \sectfont #1\par\nobreak
%      \vskip 40\p@
    %
    % The following lines do avoid printing "Chapter" before the actual chapter name.
    % Only the chapter number followed by the chapter name appear.
    %
    {\chapsize {\sectfont
     \@hangfrom{\ifnum \c@secnumdepth >\m@ne%
                  \chapterformat\fi}%
              {\raggedright \interlinepenalty \@M #1\par}}
     \nobreak
     \vskip 40\p@
    }}
\else
    %
    % This was taken from the scrreprt.cls class file.
    %
    \def\@makechapterhead#1{%
    \vspace*{50\p@}%
    {\chapsize {\sectfont
     \@hangfrom{\ifnum \c@secnumdepth >\m@ne%
                  \chapterformat\fi}%
              {\raggedright \interlinepenalty \@M #1\par}}
     \nobreak
     \vskip 40\p@
    }}
\fi

%
% This was taken from the scrreprt.cls class file.
%
\def\@makeschapterhead#1{%
  \vspace*{50\p@}%
  {\parindent \z@ \raggedright
    \normalfont
    \chapsize \sectfont #1\par
    \nobreak
    \vskip 40\p@
  }}

%
% \varchapter[#1]{#2}{#3}: Setze #3 vor die Überschrift
% (e.g. for citations)
%
% This was taken from the scrreprt.cls class file.
%
\long\def\varchapter{\if@openright\cleardoublepage\else\clearpage\fi
                    \thispagestyle{plain}%
                    \global\@topnum\z@
                    \@afterindentfalse
                    \secdef\@varchapter\@varschapter}

%
% This was taken from the scrreprt.cls class file.
%
\long\def\@varchapter[#1]#2#3{%
                    \ifnum \c@secnumdepth >\m@ne
                         \refstepcounter{chapter}%
%                         \typeout{\@chapapp\space\thechapter.}%
                         \typeout{\thechapter.}%
                         \addcontentsline{toc}{chapter}%
                                   {\protect\numberline{\thechapter}#1}%
                    \else
                      \addcontentsline{toc}{chapter}{#1}%
                    \fi
                    \chaptermark{#1}%
                    \addtocontents{lof}{\protect\addvspace{10\p@}}%
                    \addtocontents{lot}{\protect\addvspace{10\p@}}%
                    #3\par
                    \if@twocolumn
                      \@topnewpage[\@makechapterhead{#2}]%
                    \else
                      \@makechapterhead{#2}%
                      \@afterheading
                    \fi}

%
% This was taken from the scrreprt.cls class file.
%
\long\def\@varschapter#1#2{#2\par
                 \if@twocolumn
                   \@topnewpage[\@makeschapterhead{#1}]%
                 \else
                   \@makeschapterhead{#1}%
                   \@afterheading
                 \fi}

\renewcommand\chapterformat{\thechapter\if@altsecnumformat.\fi\quad}

\renewcommand\section{\@startsection{section}{1}{\z@}%
                                   {-3.5ex \@plus -1ex \@minus -.2ex}%
                                   {2.3ex \@plus.2ex}%
                                   {\normalfont\sectionsize\sectfont}}
\renewcommand\subsection{\@startsection{subsection}{2}{\z@}%
                                     {-3.25ex\@plus -1ex \@minus -.2ex}%
                                     {1.5ex \@plus .2ex}%
                                     {\normalfont\subsectionsize\sectfont}}
\renewcommand\subsubsection{\@startsection{subsubsection}{3}{\z@}%
                                     {-3.25ex\@plus -1ex \@minus -.2ex}%
                                     {1.5ex \@plus .2ex}%
                                     {\normalfont\subsubsectionsize\sectfont}}
\renewcommand\paragraph{\@startsection{paragraph}{4}{\z@}%
                                    {3.25ex \@plus1ex \@minus.2ex}%
                                    {-1em}%
                                    {\normalfont\paragraphsize\sectfont}}
\renewcommand\subparagraph{\@startsection{subparagraph}{5}{\parindent}%
                                       {3.25ex \@plus1ex \@minus .2ex}%
                                       {-1em}%
                                       {\normalfont\subparagraphsize\sectfont}}

%
% This was taken from the scrreprt.cls class file.
%
\AtEndDocument{\if@filesw
    \immediate\write\@auxout{\string\global\string\@altsecnumformatfalse}
\fi}

%
% Set figure captions.
%
\newcommand{\CapLabSep}{.5em}
\newcommand{\CapLeftMar}{2em}
\newcommand{\CapWidth}{.85\textwidth}

%
% Indent figure caption beginning from second line.
%
% This was taken from the report.cls class file.
%
\long\def\@makecaption#1#2{%
    \vskip\abovecaptionskip
%    \small\sbox\@tempboxa{\textbf{#1:} #2}%
    % This line was the originally used one.
%    \small\sbox\@tempboxa{\textbf{#1:}\hspace{\CapLabSep}#2}%
    % This line uses roman font for captions.
%    \footnotesize\sbox\@tempboxa{\textrm{\textbf{#1:}\hspace{\CapLabSep}#2}%
    % This line uses sans serif font and no bold numbers for captions.
    \footnotesize\sbox\@tempboxa{\textsf{#1:\hspace{\CapLabSep}#2}}%
    \ifdim \wd\@tempboxa >\hsize
%        \textbf{#1:} #2\par
        \begin{list}{}{%
            \setlength{\topsep}{0pt}%
            \setlength{\labelsep}{\CapLabSep}%
            \setlength{\leftmargin}{\CapLeftMar}%
            \labelwidth\z@\itemindent-\leftmargin
            \let\makelabel\erklaerungslabel}
            \item[#1:] #2
        \end{list}\par
    \else
        \global \@minipagefalse
        \hb@xt@\hsize{\hfil\box\@tempboxa\hfil}%
    \fi
    \vskip\belowcaptionskip}

%
% Indent figure caption from left and right.
%
% This was taken from the report.cls class file.
%
\long\def\@makecaption#1#2{%
    \vskip\abovecaptionskip
    % This line was the originally used one.
%    \small\sbox\@tempboxa{\textbf{#1:}\hspace{\CapLabSep}#2}%
    % This line uses roman font for captions.
%    \footnotesize\sbox\@tempboxa{\textrm{\textbf{#1:}\hspace{\CapLabSep}#2}}%
    % This line uses sans serif font and no bold numbers for captions.
    \footnotesize\sbox\@tempboxa{\textsf{#1:\hspace{\CapLabSep}#2}}%
    \ifdim \wd\@tempboxa >\CapWidth
        \hfil\parbox{\CapWidth}{\textbf{#1:}\hspace{\CapLabSep}#2}\hfil\par
    \else
        \global \@minipagefalse
        \hb@xt@\hsize{\hfil\box\@tempboxa\hfil}%
    \fi
    \vskip\belowcaptionskip}

%
% Adapt footnote text.
%
% This was taken from the scrreprt.cls class file.
%
\newlength{\sc@temp}
\long\def\@makefntext#1{%
    \noindent \sc@temp\columnwidth%
    \advance\sc@temp by -1.5em%
    \hb@xt@1em{\hss\@makefnmark}\hskip.1em%
    \parbox[t]{\sc@temp}{%\parindent\z@\parskip\z@\hskip-.5em
    #1}}

%
% Provide enumeration with roman numbers.
%
% This was taken from the LaTeX Companion, 3.2.1.
%
\newenvironment{enumerateRoman}{%
    \renewcommand{\theenumi}{\Roman{enumi}}%
    \renewcommand{\labelenumi}{\theenumi.}%
    \renewcommand{\theenumii}{\Alph{enumii}}%
    \renewcommand{\labelenumii}{\theenumii.}%
    \renewcommand{\p@enumii}{\theenumi--}%
    \begin{enumerate}}{\end{enumerate}}
\endinput

%
% Avoid "overfull hbox".
%
\tolerance=2000
\emergencystretch 20pt
