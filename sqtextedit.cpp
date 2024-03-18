#include "sqtextedit.h"

using namespace sodium;

SQTextEdit::SQTextEdit(QWidget *parent)
    : SQEditBase<SQTextEditBase>(parent)
{
    connect(this, &QTextEdit::textChanged, [this] { m_text.setUserValue(toPlainText()); });
}
