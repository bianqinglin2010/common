// tianyi accelerator framework

#ifndef _HPC_TIANYI_COMMON_STRIPFILENAME_H_
#define _HPC_TIANYI_COMMON_STRIPFILENAME_H_

#include <string.h>

namespace tianyi { namespace common {

/*!
 * @stripfilename
 * Get file name from the full path.
 * ./xxx/abc.cc -> abc.cc
 * @remark
 * Modern compiler can optimize the call
 * of the function, if the parameter is
 * a compilation runtime constant, such
 * as __FILE__
 ************************************/
inline const char* stripfilename(const char* filename) {
    const size_t l = strlen(filename);
    const char* end = filename + l;
    while (end >= filename) {
        if (
#ifdef _MSC_VER
            *end == '/' || *end == '\\'
#else
            *end == '/'
#endif
        ) {
            return end + 1;
        }
        // "--" is ok. For filename is not null.
        --end;
    }
    return filename;
}

}} // namespace tianyi::common
#endif
