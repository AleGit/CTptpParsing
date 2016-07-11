//  PrlcCore.h
//  Copyright © 2016 Alexander Maringele. All rights reserved.

#ifndef PrlcCore_h
#define PrlcCore_h

#if(linux)

#include <sys/types.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(__STDC_VERSION__) && (199901L <= __STDC_VERSION__)

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>

#endif

/* _Nullable, _Nonnull, _Null_unspecified seem unavailable on linux */

#else /* linux <> macOS */

#import <CoreFoundation/CoreFoundation.h>

#endif /* macOS */

#endif /* PrlcCore_h */
