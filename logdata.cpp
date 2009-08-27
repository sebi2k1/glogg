#include <iostream>

#include "logdata.h"

LogData::LogData(const QByteArray &byteArray)
{
    int j = 0;

    data = new QByteArray(byteArray);

    // Count the lines
    nbLines = 0;
    while (( j = data->indexOf("\n", j)) != -1) {
        nbLines++; j++;
    }
    std::cout << "Found " << nbLines << " lines." << std::endl;
}

int LogData::getNbLine()
{
    return nbLines;
}

QString LogData::getLineString(int line)
{
    int pos = 0;

    // Search the requested line
    for (int i = 0; i < line; i++, pos++)
        pos = data->indexOf("\n", pos);

    int end = data->indexOf("\n", pos);

    std::cout << "line " << line << " pos: " << pos << " end: " << end << std::endl;

    QString string = QString(data->mid(pos, end-pos));

    std::cout << string.toStdString() << std::endl;

    return string;
}