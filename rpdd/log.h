/*
 * Copyright (C) 2011 Bernhard Froehlich <decke@bluelife.at>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Author's name may not be used endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _LOG_H_
#define _LOG_H_

enum loglevels
{
    LOG_ERROR = 0,
    LOG_WARN,
    LOG_INFO
};

#define loginfo(format, args...) logwrite(LOG_INFO, format, ##args)
#define logwarn(format, args...) logwrite(LOG_WARN, format, ##args)
#define logerror(format, args...) logwrite(LOG_ERROR, format, ##args)
#define logcgi(url, error) \
{ \
    logwrite(LOG_ERROR, "CGI Error in %s#%d, %s: %s", __FILE__, __LINE__, url, error); \
}
#define logsql(con) \
{ \
    logwrite(LOG_ERROR, "SQL Error in %s#%d: %s", \
        __FILE__, __LINE__, PQerrorMessage(con)); \
}

extern int logopen(char *filename);
extern int logclose(void);
extern int logsetlevel(int loglvl);
extern int logwrite(int loglvl, char *logfmt, ...);

#endif /* _LOG_H_ */
