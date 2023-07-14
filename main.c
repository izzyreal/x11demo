#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Display* d;
    Window w;
    XEvent e;

    d = XOpenDisplay(NULL);

    if (d == NULL)
    {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    int s = DefaultScreen(d);

    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 200, 200, 1,
                            BlackPixel(d, s), WhitePixel(d, s));

    Atom delWindow = XInternAtom(d, "WM_DELETE_WINDOW", 0);
    XSetWMProtocols(d, w, &delWindow, 1);

    XSizeHints* size_hints = XAllocSizeHints();
    size_hints->flags = PAspect;
    size_hints->min_aspect.x = 1;
    size_hints->min_aspect.y = 1;
    size_hints->max_aspect.x = 1;
    size_hints->max_aspect.y = 1;
    XSetWMNormalHints(d, w, size_hints);

    XMapWindow(d, w);
    XFlush(d);

    while (1)
    {
        XNextEvent(d, &e);
        if (e.type == ClientMessage)
        { break; }
    }

    XFree(size_hints);
    XCloseDisplay(d);

    return 0;
}
