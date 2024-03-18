#pragma once

#include "sqwidgetbase.h"

#include <QPushButton>

#include <sodium/sodium.h>

class SQPushButton : public SQWidgetBase<QPushButton>
{
public:
    explicit SQPushButton(QWidget *parent = nullptr);
    SQPushButton(const char text[], QWidget *parent = nullptr);
    SQPushButton(const sodium::cell<QString> &text, QWidget *parent = nullptr);

    void setText(const sodium::cell<QString> &text);

    const sodium::stream<sodium::unit> &clicked() const;

private:
    sodium::stream_sink<sodium::unit> m_clicked;
    Unsubscribe m_unsubscribe;
};
