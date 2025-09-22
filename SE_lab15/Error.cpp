#include "stdafx.h"
#include "Error.h"
namespace Error
{
    // серии ошибок:   0 -  99 - системные ошибки
    //               100 - 109 - ошибки параметров
    //               110 - 119 - ошибки открытия и чтения файлов
    ERROR errors[ERROR_MAX_ENTRY] =  // таблица ошибок
    {
      ERROR_ENTRY(0, "недопустимый код ошибки"),   // код ошибки вне диапазона 0 - ERROR_MAX_ENTRY
      ERROR_ENTRY(1, "Системный сбой"),
      ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
      ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
      ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
      ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
      ERROR_ENTRY(100, "Параметр -in должен быть задан"),
      ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
      ERROR_ENTRY(104, "Превышена длина входного файла"),
      ERROR_ENTRY(105, "Параметры -in и -log совпадают"),
      ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
      ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
      ERROR_ENTRY(110, "Ошибка при открытии файла с исходным кодом (-in)"),
      ERROR_ENTRY(111, "Недопустимый символ в исходном файле (-in)"),
      ERROR_ENTRY(112, "Ошибка при создании файла протокола (-log)"),
      ERROR_ENTRY(113, "Ошибка при создании файла протокола (-out)"),
      ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115),
      ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
      ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
      ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
      ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
      ERROR_ENTRY_NODEF100(600), ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
    };
    ERROR geterror(int id) {
        ERROR er;
        if (id <= 0 || id >= ERROR_MAX_ENTRY)
        {
            er = errors[0];
        }
        else
        {
            er = errors[id];
        }

        return er;
    }
    ERROR geterrorin(int id, int line = -1, int col = 0)
    {
        ERROR er;

        if (id <= 0 || id >= ERROR_MAX_ENTRY)
        {
            er = errors[0];
        }
        else
        {
            er = errors[id];
        }

        er.inext.col = col;
        er.inext.line = line;

        return er;
    }
}
