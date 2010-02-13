#include "fitz.h"
#include "mupdf.h"

#include <android/log.h>

/*
 * Enable logging by setting environment variable MULOG to:
 *   (a)ll or a combination of
 *   (x)ref (r)src (f)ont (i)mage (s)hade (p)age
 *
 * eg. MULOG=fis ./x11pdf mytestfile.pdf
 */

enum
{
	PDF_LXREF = 1,
	PDF_LRSRC = 2,
	PDF_LFONT = 4,
	PDF_LIMAGE = 8,
	PDF_LSHADE = 16,
	PDF_LPAGE = 32
};

static inline void pdflog(int tag, char *name, char *fmt, va_list ap)
{
	static int flags = 0;

	if (!(flags & tag))
		return;

	__android_log_print(ANDROID_LOG_DEBUG, "MuPDF", fmt, ap);
}

void pdf_logxref(char *fmt, ...)
{va_list ap;va_start(ap,fmt);pdflog(PDF_LXREF,"xref",fmt,ap);va_end(ap);}

void pdf_logrsrc(char *fmt, ...)
{va_list ap;va_start(ap,fmt);pdflog(PDF_LRSRC,"rsrc",fmt,ap);va_end(ap);}

void pdf_logfont(char *fmt, ...)
{va_list ap;va_start(ap,fmt);pdflog(PDF_LFONT,"font",fmt,ap);va_end(ap);}

void pdf_logimage(char *fmt, ...)
{va_list ap;va_start(ap,fmt);pdflog(PDF_LIMAGE,"imag",fmt,ap);va_end(ap);}

void pdf_logshade(char *fmt, ...)
{va_list ap;va_start(ap,fmt);pdflog(PDF_LSHADE,"shad",fmt,ap);va_end(ap);}

void pdf_logpage(char *fmt, ...)
{va_list ap;va_start(ap,fmt);pdflog(PDF_LPAGE,"page",fmt,ap);va_end(ap);}
