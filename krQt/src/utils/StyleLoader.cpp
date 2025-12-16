#include "utils/StyleLoader.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

QString StyleLoader::loadStyleSheet(const QString& filename) {
    QFile file(filename);
    
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qWarning() << "Failed to open stylesheet:" << filename;
        return QString();
    }
    
    QTextStream stream(&file);
    QString styleSheet = stream.readAll();
    file.close();
    
    return styleSheet;
}

