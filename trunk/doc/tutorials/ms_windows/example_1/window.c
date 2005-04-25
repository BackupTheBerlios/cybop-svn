/*Programm zur erstellung von einem fenster mit buton*/

#include <windows.h>
#include <string.h>

/* Windowsfunktion für main fenster, sobald message ausgeführtwird durch "DispatchMessage" oder   * gesendet durch "SendMessage" wird diese funktion mit dem inhalt aufgerufen*/

LRESULT CALLBACK
MainWndProc (HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
        /* window handle für "Drück" button. */
        static HWND   hwndButton = 0;
        static int    cx, cy;          /* Höhe und Breite button */

        HDC           hdc;             
        PAINTSTRUCT   ps;              
        RECT          rc;              /* ein rechteck für das zeichnen */

        
	/* Entscheidung wie es weiter geht, in bezug auf erhaltenen messsages(ereignisse) */
        switch (nMsg)
        {
                case WM_CREATE:
                {
                        /* Das Fenster wurde erzeugt. Erzeuge das Buttonfenster jetzt*/
                        TEXTMETRIC        tm;

                        /* Systemeingestellte Schriftgröße wählen ->gute buttongröße */
                        hdc = GetDC (hwnd);
                        SelectObject (hdc, GetStockObject (SYSTEM_FIXED_FONT));
                        GetTextMetrics (hdc, &tm);
                        cx = tm.tmAveCharWidth * 30;
                        cy = (tm.tmHeight + tm.tmExternalLeading) * 2;
                        ReleaseDC (hwnd, hdc);

                        /* Jetzt Button erzeugen*/
                        hwndButton = CreateWindow (
                                "button",         /* Button klasse erzeugen */
                                "Beeneden",
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                0, 0, cx, cy,
                                hwnd,             /* Parent ist dieses fenster. */
                                (HMENU) 1,        /* Control ID: 1 */
                                ((LPCREATESTRUCT) lParam)->hInstance,
                                NULL
                                );

                        return 0;
                        break;
                }

                case WM_DESTROY:
                        /* das fenster wurde zerstört(geschlossen), schließe die anwendung
                         * (der child button wird automatisch zerstört */
                        PostQuitMessage (0);
                        return 0;
                        break;

                case WM_PAINT:
                        /* das fenster muss gezeichnet werden (erneuern). */
                        hdc = BeginPaint (hwnd, &ps);
                        GetClientRect (hwnd, &rc);

                        /* Zeichne "Hallo Christian" in die mitte des oberen hablfensters*/
                        rc.bottom = rc.bottom / 2;
                        DrawText (hdc, "Hallo Christian", -1, &rc,
                                DT_SINGLELINE | DT_CENTER | DT_VCENTER);

                        EndPaint (hwnd, &ps);
                        return 0;
                        break;

                case WM_SIZE:
                        /* fenstergröße verändert sich.wenn der button existiert,dann platziere 			 *ihn in der mitte des fenster */
                        if (hwndButton &&
                                (wParam == SIZEFULLSCREEN ||
                                 wParam == SIZENORMAL)
                           )
                        {
                                rc.left = (LOWORD(lParam) - cx) / 2;
                                rc.top = HIWORD(lParam) * 3 / 4 - cy / 2;
                                MoveWindow (
                                        	hwndButton,
                                        	rc.left, rc.top, cx, cy, TRUE);
                        }
                        break;

                case WM_COMMAND:
                        /* überprüfen der control ID, notification code und
                         * control handle zum überprüfen ob dies eine button click message für das 			 *child fenster ist*/
                        if (LOWORD(wParam) == 1 &&
                            HIWORD(wParam) == BN_CLICKED &&
                            (HWND) lParam == hwndButton)
                        {
                                /* Button geklickt ->Schließe fenster */
                                DestroyWindow (hwnd);
                        }
                        return 0;
                        break;
        }

        /* sobald eine message nicht komplett behandelt wird, wird sie an das system 	 	 	 	 *übergeben für standart windows funktionen*/
        return DefWindowProc (hwnd, nMsg, wParam, lParam);
}


int STDCALL
WinMain (HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{

        /* als erstes erzeugen einer fensterklasse für das hauptfenster*/
	HWND         hwndMain;        /* Handle für hauptfenster */
        MSG          msg;             /* eine Win32 message striktur */
        WNDCLASSEX   wndclass;        /* eine fensterklassen struktur */
        char*        szMainWndClass = "WinTestWin";
                                      /* Name der fensterklasse */
      
        /*innitialisierung der kompletten struktur mit 0 */
        memset (&wndclass, 0, sizeof(WNDCLASSEX));

        /* diese klasse heißt WinTestWin */
        wndclass.lpszClassName = szMainWndClass;

        /* cbSize gibt die ausdehnungsgröß der struktur an*/
        wndclass.cbSize = sizeof(WNDCLASSEX);

        /* alle fenster dieser klasse werden neu gezeichnet, wenn größe geändert wird*/
        wndclass.style = CS_HREDRAW | CS_VREDRAW;

        /* alle fenster dieser klasse benutzen die MainWndProc fensterfunktion */
        wndclass.lpfnWndProc = MainWndProc;

        wndclass.hInstance = hInst;		/*????*/

        /* benutze standart anwendung icons und cusors, die vom OS zu verfügung gestellt werden*/ 		wndclass.hIcon = LoadIcon (NULL, IDI_APPLICATION);
        wndclass.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
        wndclass.hCursor = LoadCursor (NULL, IDC_ARROW);

        /* Weißer hintergrund */
        wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);

        /* Registriren der fensterklasse  */
        RegisterClassEx (&wndclass);

        /* erzeugen des hauptfensters mit hilfe der fensterklasse */
        hwndMain = CreateWindow (
                szMainWndClass,             /* Klassenname */
                "Fuck Button", 	            /* Beschriftung */
                WS_OVERLAPPEDWINDOW,        /* Style */
                CW_USEDEFAULT,              /* Initial x (standard) */
                CW_USEDEFAULT,              /* Initial y (standard) */
                CW_USEDEFAULT,              /* Initial x Größe (standard) */
                CW_USEDEFAULT,              /* Initial y Größe (standard) */
                NULL,                       /* kein parent window */
                NULL,                       /* kein menü */
                hInst,                      /* programm instanz */
                NULL                        /* parameter */
                );
        
        /* Anzeigen des erzeugten fensters(mithilfe nShow, was erlaubt, das fenster minimiert zu 		 *starten usw  */
        ShowWindow (hwndMain, nShow);
        UpdateWindow (hwndMain);

        /* Hauptschleife für nachrichten(ereignisse), alle werden mit GetMessage aufgenommen,
	 * schleife endet mit dem schließen des fensters*/
        while (GetMessage (&msg, NULL, 0, 0))
        {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
        }
        return msg.wParam;
}
