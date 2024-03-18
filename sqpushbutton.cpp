#include "sqpushbutton.h"

using namespace sodium;

SQPushButton::SQPushButton(QWidget *parent)
    : SQPushButton(QString(), parent)
{}

SQPushButton::SQPushButton(const char text[], QWidget *parent)
    : SQPushButton(QString(text), parent)
{}

SQPushButton::SQPushButton(const sodium::cell<QString> &text, QWidget *parent)
    : SQWidgetBase<QPushButton>(parent)
{
    connect(this, &QPushButton::clicked, this, [this] { m_clicked.send({}); });
    setText(text);
}

void SQPushButton::setText(const sodium::cell<QString> &text)
{
    m_unsubscribe.insert_or_assign("text",
                                   text.listen(
                                       ensureSameThread<QString>(this, &QPushButton::setText)));
}

const sodium::stream<unit> &SQPushButton::clicked() const
{
    return m_clicked;
}
