% diplom.cls

\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{diplom}[1998/04/08 v0.1]

\typeout{---------------------------------------}
\typeout{-------------- diplom.cls -------------}
\typeout{-------- urspruenglich erstellt: ------}
\typeout{-------- 1998 von Volker Ahlers -------}
\typeout{------ aufbereitet für TU-Ilmenau -----}
\typeout{---------- von Torsten Kunze ----------}
\typeout{-- (basiert auf KOMA scrreprt class) --}
\typeout{---------------------------------------}

%benötigte Packages:
%Deutsche Schrift
\usepackage[german]{babel}
%Eingabe von ü,ö,ä,ß erlaubt:
\usepackage[latin1]{inputenc}
%\usepackage{float}
\usepackage{graphicx}
%\usepackage[dvips]{graphicx}
%\usepackage[dvips,draft]{graphicx}

\usepackage{psfrag}
\usepackage{fancyhdr}
\usepackage{bibgerm}


\newcommand{\myglossary}[2]{\emph{#1}\glossary{#1}\glossary{#1!#2}}
\newcommand{\strich}{\begin{center}\rule{10cm}{1.5pt}\end{center}}

\DeclareGraphicsRule{.jpg}{eps}{}{}

\newcommand{\incljpg}[5]{
\begin{figure}[h]
    \begin{center}

        \leavevmode
        \includegraphics[bb=#1]{#2}

        \caption[#3]{#4}
        \label{#5}
    \end{center}
\end{figure}
}


\newcommand{\includepicture}[6]{
\begin{figure}[h]
    \begin{center}
        \leavevmode
        \includegraphics*[width=#1cm]{#2}
        \caption[#3]{#4}
        \label{#5}
    \end{center}
\end{figure}
}

%set margin as follows: 
    %1st parameter: odd side margin
    %2nd parameter: text width
    %3rd parameter: text heigth
\newcommand{\setMargins[3]}{
    \setlength{\hoffset}{-1in} 
    \setlength{\oddsidemargin}{#1cm} 
    \setlength{\textwidth}{#2cm}
    \setlength{\textheight}{#3cm}
}

%setting archiv number as footer
\newcommand{\setFooter}{
    \rfoot{\small Inv.-Nr.: 2003-01-02/005/IN97/2232}   
    \lfoot{\small Torsten Kunze}   
}

\newcommand{\@BaseClass}{scrreprt}
\newif\if@kapitel

\DeclareOption{11pt}{\PassOptionsToClass{\CurrentOption,DIV12}{\@BaseClass}}
\DeclareOption{12pt}{\PassOptionsToClass{\CurrentOption,DIV14}{\@BaseClass}}
\DeclareOption{oneside}{\@twosidefalse}
\DeclareOption{twoside}{\@twosidetrue}
\DeclareOption{openright}{\PassOptionsToClass{\CurrentOption}{\@BaseClass}}
\DeclareOption{openany}{\PassOptionsToClass{\CurrentOption}{\@BaseClass}}
\DeclareOption{kapitel}{\@kapiteltrue}
\DeclareOption{nokapitel}{\@kapitelfalse}

\ExecuteOptions{11pt,oneside,kapitel}
\ProcessOptions

\if@twoside
  \PassOptionsToClass{twoside}{\@BaseClass}
\else
  \PassOptionsToClass{oneside}{\@BaseClass}
\fi

\LoadClass[headsepline,BCOR10mm]{\@BaseClass}

\RequirePackage{fancyhdr}


%-----------------------------------------------------------------
%              Layout
%-----------------------------------------------------------------

\renewcommand{\footrulewidth}{0.4pt}
\renewcommand{\baselinestretch}{1.50}\normalsize

% Ersetze:
%\setlength{\parindent}{1em}
%\setlength{\parskip}{1.5ex plus0.5ex minus0.5ex}
% durch 
\RequirePackage{parskip}
% auf Anraten von Bernd Raichle <raichle@Informatik.Uni-Stuttgart.DE>

\tolerance=2000                     % Zur Vermeidung von "overfull hbox"
\emergencystretch 20pt   

%-----------------------------------------------------------------
%            Größen, Namen etc.
%-----------------------------------------------------------------

% Überschriften
\renewcommand{\sectfont}{\bf} %\sffamily\bfseries
\newcommand{\chapsize}{\LARGE}
\newcommand{\sectionsize}{\Large}
\newcommand{\subsectionsize}{\large}
\newcommand{\subsubsectionsize}{\normalsize}
\newcommand{\paragraphsize}{\normalsize}
\newcommand{\subparagraphsize}{\normalsize}

% figure captions
\newcommand{\CapLabSep}{.5em}       
\newcommand{\CapLeftMar}{2em}
\newcommand{\CapWidth}{.85\textwidth}


% Für headers
\if@kapitel
  \newcommand{\HeadKap}{Kapitel}
\else
  \newcommand{\HeadKap}{}
\fi
\newcommand{\HeadKapSep}{.8em}




%-----------------------------------------------------------------
%              Headers
%-----------------------------------------------------------------

\pagestyle{fancy}      % Muß vor den folgenden Definitionen stehen!

\if@twoside         % zweiseitiger Druck
  \renewcommand{\chaptermark}[1]{%
                \markboth{\HeadKap~\thechapter\hspace{\HeadKapSep}#1}%
                        {\HeadKap~\thechapter\hspace{\HeadKapSep}#1}}
  \renewcommand{\sectionmark}[1]{\markright{\thesection\hspace{\HeadKapSep}#1}}
  \lhead[\fancyplain{}{\textsf{\thepage}}]{\fancyplain{}{\rightmark}}
  \rhead[\fancyplain{}{\leftmark}]{\fancyplain{}{\textsf{\thepage}}}
  \cfoot{\fancyplain{\textsf{\thepage}}{}}
  \newcommand{\clearemptydoublepage}{\newpage{\pagestyle{empty}%
                                \cleardoublepage}} % (Companion, 4.3)
\else               % einseitiger Druck
  \renewcommand{\chaptermark}[1]{
                \markboth{\HeadKap~\thechapter\hspace{\HeadKapSep}#1}%
                        {\HeadKap~\thechapter\hspace{\HeadKapSep}#1}}
  \renewcommand{\sectionmark}[1]{}
  \lhead[\fancyplain{}{\rightmark}]{\fancyplain{}{\rightmark}}
  \rhead[\fancyplain{}{\thepage}]{\fancyplain{}{\thepage}}  
  
  \cfoot{\fancyplain{\thepage}{}}
  \newcommand{\clearemptydoublepage}{\clearpage}
\fi


%-----------------------------------------------------------------
%              Überschriften
%-----------------------------------------------------------------

% (aus scrreprt.cls)
\renewcommand\chapter{\if@openright\clearemptydoublepage\else\clearpage\fi
                    \thispagestyle{plain}%
                    \global\@topnum\z@
                    \@afterindentfalse
                    \secdef\@chapter\@schapter}

% (aus scrreprt.cls)
\renewcommand\addchap{\if@openright\clearemptydoublepage\else\clearpage\fi
                    \thispagestyle{plain}%
                    \global\@topnum\z@
                    \@afterindentfalse
                    \secdef\@addchap\@saddchap}

\if@kapitel
  % (aus report.cls)
  \def\@makechapterhead#1{%
    \vspace*{50\p@}%
    {\parindent \z@ \raggedright
      \ifnum \c@secnumdepth >\m@ne
        \chapsize \sectfont \@chapapp{} \thechapter 
        \par\nobreak
        \vskip 0\p@
      \fi
      \interlinepenalty\@M
      \chapsize \sectfont #1\par\nobreak
      \vskip 40\p@
    }}
\else
  % (aus scrreprt.cls)
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

% (aus scrreprt.cls)
\def\@makeschapterhead#1{%
  \vspace*{50\p@}%
  {\parindent \z@ \raggedright
    \normalfont
    \chapsize \sectfont #1\par
    \nobreak
    \vskip 40\p@
  }}

% \varchapter[#1]{#2}{#3}: Setze #3 vor die Überschrift
%   (z.B. für Zitate)
% (aus scrreprt.cls)
\long\def\varchapter{\if@openright\cleardoublepage\else\clearpage\fi
                    \thispagestyle{plain}%
                    \global\@topnum\z@
                    \@afterindentfalse
                    \secdef\@varchapter\@varschapter}
% (aus scrreprt.cls)
\long\def\@varchapter[#1]#2#3{%
                    \ifnum \c@secnumdepth >\m@ne
                         \refstepcounter{chapter}%
                         \typeout{\@chapapp\space\thechapter.}%
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
% (aus scrreprt.cls)
\long\def\@varschapter#1#2{#2\par
                 \if@twocolumn
                   \@topnewpage[\@makeschapterhead{#1}]%
                 \else
                   \@makeschapterhead{#1}%
                   \@afterheading
                 \fi}

\renewcommand\chapterformat {\thechapter\if@altsecnumformat.\fi\quad}

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

% (aus scrrprt.cls)
\AtEndDocument{\if@filesw
    \immediate\write\@auxout{\string\global\string\@altsecnumformatfalse}
  \fi}

%-----------------------------------------------------------------
%         figure captions
%-----------------------------------------------------------------

% Caption ab zweiter Zeile eingerückt:
% (aus report.cls)
\long\def\@makecaption#1#2{%
  \vskip\abovecaptionskip
%  \small\sbox\@tempboxa{\textbf{#1:} #2}%
  \small\sbox\@tempboxa{\textbf{#1:}\hspace{\CapLabSep}#2}%
  \ifdim \wd\@tempboxa >\hsize
%    \textbf{#1:} #2\par
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

% Caption links und rechts eingerückt:
% (aus report.cls)
\long\def\@makecaption#1#2{%
  \vskip\abovecaptionskip
  \small\sbox\@tempboxa{\textbf{#1:}\hspace{\CapLabSep}#2}%
  \ifdim \wd\@tempboxa >\CapWidth
    \hfil\parbox{\CapWidth}{\textbf{#1:}\hspace{\CapLabSep}#2}\hfil\par
  \else
    \global \@minipagefalse
    \hb@xt@\hsize{\hfil\box\@tempboxa\hfil}%
  \fi
  \vskip\belowcaptionskip}

%-----------------------------------------------------------------
%         Fußnoten
%-----------------------------------------------------------------

% (aus scrrprt.cls)
\newlength{\sc@temp}
\long\def\@makefntext#1{%
  \noindent \sc@temp\columnwidth%
  \advance\sc@temp by -1.5em%
  \hb@xt@1em{\hss\@makefnmark}\hskip.1em%
  \parbox[t]{\sc@temp}{%\parindent\z@\parskip\z@\hskip-.5em
                        #1}}


%-----------------------------------------------------------------
%       Neue Makros, Umgebungen etc.
%-----------------------------------------------------------------

\newenvironment{erklaerung}{%
  \list{}{\setlength{\leftmargin}{0pt}%   \parindent}%
     \labelwidth\z@ \itemindent-\leftmargin
     \let\makelabel\erklaerungslabel}}%
  {\endlist}
\newcommand*\erklaerungslabel[1]{\hspace\labelsep
                                \normalfont\bfseries #1}

% Aus LaTeX Companion, 3.2.1
\newenvironment{enumerateRoman}{%
  \renewcommand{\theenumi}{\Roman{enumi}}%
  \renewcommand{\labelenumi}{\theenumi.}%
  \renewcommand{\theenumii}{\Alph{enumii}}%
  \renewcommand{\labelenumii}{\theenumii.}%
  \renewcommand{\p@enumii}{\theenumi--}%
  \begin{enumerate}}{\end{enumerate}}
\endinput

\renewcommand{\ps@plain}
    {\let\@mkboth\@gobbletwo
    \renewcommand{\@oddhead}{}
    \renewcommand{\@evenhead}{}
    \renewcommand{\@oddfoot}{BLA}
    \renewcommand{\@evenfoot}{\hfil\thepage\hfil}
}
