#ifndef POPUP_ADDCOLUMN_H
#define POPUP_ADDCOLUMN_H

#include <QDialog>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
class QGroupBox;
QT_END_NAMESPACE

class Popup_AddColumn : public QDialog
{
    Q_OBJECT

public:
    Popup_AddColumn();
    ~Popup_AddColumn();

private:
    void createWindow();
    void createForm();
    void createBottomOptions();
    void closeEvent(QCloseEvent *event);

    //Frames and layers
    QGroupBox *mainWindow;
    QGroupBox *verticalGroupBox;
    QGroupBox *formBox;
    QGroupBox *bottomOptionsBox;

    //Buttons
    QPushButton *acceptButton;
    QPushButton *cancelButton;

    //Text feilds
    QLineEdit *columnName;

private slots:
    void on_acceptButton_clicked();
    void on_cancelButton_clicked();

};

class Popup_AddColumn_Return
{
public:
    Popup_AddColumn_Return();

private:

};

#endif // POPUP_ADDCOLUMN_H
