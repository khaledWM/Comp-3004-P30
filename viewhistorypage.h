#ifndef VIEWHISTORYPAGE_H
#define VIEWHISTORYPAGE_H
#include"page.h"
#include "recording.h"
#include"QLabel"
#include"QGridLayout"
class ViewHistoryPage : public Page
{
    Q_OBJECT
public:
    ViewHistoryPage(QWidget *parent=nullptr);
    ~ViewHistoryPage();

private:
    QGridLayout *layout;
    int row=0;
    int col=0;
private slots:
    void addRecording(Recording*);


};

#endif // VIEWHISTORYPAGE_H
