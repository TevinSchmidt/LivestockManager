#ifndef POPUP_ADDCOLUMN_H
#define POPUP_ADDCOLUMN_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QGroupBox;
QT_END_NAMESPACE

class Popup_AddColumn : public QDialog
{
    Q_OBJECT

public:
    Popup_AddColumn();

private:
    void createWindow();
    void createForm();

    QGroupBox *mainWindow;

};

class Popup_AddColumn_Return
{
public:
    Popup_AddColumn_Return();

private:

};

#endif // POPUP_ADDCOLUMN_H
