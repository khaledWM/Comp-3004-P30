#ifndef BUTTON_H
#define BUTTON_H
#include <QToolButton>
#include<QPushButton>

class Button: public QPushButton{
    Q_OBJECT


private slots:
    void upButtonClicked();
    void downButtonClicked();
    void rightButtonClicked();
    void leftButtonClicked();


public:
    Button(const QString &text,int x, int y,QWidget *parent =nullptr);
    QSize sizeHint() const override;



};

#endif // BUTTON_H
