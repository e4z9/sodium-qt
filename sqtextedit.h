#pragma once

#include <sqeditbase.h>

#include <sodium/sodium.h>

class SQTextEdit : public SQEditBase<SQTextEditBase>
{
public:
    explicit SQTextEdit(QWidget *parent = nullptr);
};
