#ifndef VIEWHISTORYPAGE_H
#define VIEWHISTORYPAGE_H
#include"page.h"
#include "recording.h"
#include"QLabel"
#include"QGridLayout"
class ViewHistoryPage : public Page
{
public:
    ViewHistoryPage(QWidget *parent=nullptr);
    ~ViewHistoryPage();

private:
    QGridLayout *layout;
private slots:
    void addRecording(int);

};

#endif // VIEWHISTORYPAGE_H
