#include "sqeditbase.h"

SQTextEditBase::SQTextEditBase(QWidget *parent)
    : QTextEdit(parent)
{}

void SQTextEditBase::setText(const QString &text)
{
    setPlainText(text);
}

QString SQTextEditBase::text() const
{
    return toPlainText();
}
