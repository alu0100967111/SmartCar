#include "error.h"

error::error()
{

}

warningerror::warningerror(QString title, QString description){
    QMessageBox::warning(this, title, description);
}

criticalerror::criticalerror(QString title, QString description){
    QMessageBox::critical(this, title, description);
}

informationerror::informationerror(QString title, QString description){
    QMessageBox::information(this, title, description);
}
