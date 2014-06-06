#include <QCoreApplication>

#include "TCollectionUtilities.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TCollectionUtilities tCollectionUtilities;
    QTest::qExec(&tCollectionUtilities);
    
    class Stroka
    {
        
    };

    return 0;
}
