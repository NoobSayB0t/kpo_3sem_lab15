#include "stdafx.h"
#include "Parm.h"
#include "Error.h"


namespace Parm
{
    PARM getparm(int argc, wchar_t* argv[])
    {
        PARM parm;

        bool parm_in_find = false,
            parm_out_find = false,
            parm_log_find = false;

        wchar_t* tempParam;

        for (int i = 1; i < argc; i++)
        {
            if (wcslen(argv[i]) < PARM_MAX_SIZE)
            {
                if (tempParam = wcsstr(argv[i], PARM_IN))
                {
                    tempParam += wcslen(PARM_IN);
                    wcscpy_s(parm.in, tempParam);
                    parm_in_find = true;
                }
                if (tempParam = wcsstr(argv[i], PARM_OUT))
                {
                    tempParam += wcslen(PARM_OUT);
                    wcscpy_s(parm.out, tempParam);
                    parm_out_find = true;
                }
                if (tempParam = wcsstr(argv[i], PARM_LOG))
                {
                    tempParam += wcslen(PARM_LOG);
                    wcscpy_s(parm.log, tempParam);
                    parm_log_find = true;
                }
            }
            else
                throw ERROR_THROW(104);
        }

        if (!parm_in_find)
            throw ERROR_THROW(100);

        if (!parm_out_find)
        {
            wcscpy_s(parm.out, parm.in);
            wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
        }

        if (!parm_log_find)
        {
            wcscpy_s(parm.log, parm.in);
            wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
        }

        if (wcscmp(parm.in, parm.log) == 0)
        {
            throw ERROR_THROW(105);
        }

        return parm;
    }
}
