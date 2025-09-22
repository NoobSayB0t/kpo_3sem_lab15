#pragma once
#include "In.h"
#include "Parm.h"
#include "Error.h"
#include"stdafx.h"

#pragma warning(disable: 4996)

using namespace std;

namespace Log
{
    struct LOG
    {
        wchar_t* logfile;
        ofstream* stream;

        LOG()
        {
            this->logfile = new wchar_t[PARM_MAX_SIZE];
            this->stream = new ofstream;
        }
    };

    LOG getlog(wchar_t* logfile);
    void WriteLine(LOG log, const char* c, ...);
    void WriteLine(LOG log, const wchar_t* c, ...);
    void WriteLog(LOG log);
    void WriteParm(LOG log, Parm::PARM parm);
    void WriteIn(LOG log, In::IN in);
    void WriteError(LOG log, Error::ERROR error);
    void Close(LOG log);
}
