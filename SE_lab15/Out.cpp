#include "stdafx.h"
#include "Out.h"
#include <locale>
#include <codecvt>
#include <iostream>
#include <fstream>

namespace Out {

    OUT getout(wchar_t outfile[]) {
        OUT out;
        out.stream = new std::wofstream;
        out.stream->open(outfile);
        if (!out.stream->is_open()) {
            throw ERROR_THROW(113);
        }
        // Настройка кодировки UTF-8 для wide-стрима
        out.stream->imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
        wcscpy_s(out.outfile, outfile);
        return out;
    }

    void WriteToFile(OUT out, In::IN in) {
        *out.stream << in.text;
    }

    void WriteToError(OUT out, Error::ERROR error) {
        if (out.stream && out.stream->is_open()) {
            *out.stream << L"Ошибка " << error.id << L": " << error.message << std::endl;
            if (error.inext.line != -1) {
                *out.stream << L"Строка: " << error.inext.line
                            << L" Позиция: " << error.inext.col << std::endl << std::endl;
            }
        }
        else {
            std::wcout.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
            std::wcout << L"Не удалось открыть файл" << std::endl;
        }
    }

    void CloseFile(OUT out) {
        if (out.stream) {
            out.stream->close();
            delete out.stream;
        }
    }
}
