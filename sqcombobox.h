#pragma once

#include "sqwidgetbase.h"

#include <QComboBox>

#include <sodium/sodium.h>

template<class T>
class SQComboBox : public SQWidgetBase<QComboBox>
{
public:
    struct Item
    {
        QString displayName;
        T value;
    };

    SQComboBox(const QVector<Item> &items, QWidget *parent = nullptr);

    const sodium::cell<std::optional<T>> &currentItem() const;

private:
    void setIndex(std::optional<int> i);

    const QVector<Item> m_items;
    UserValue<std::optional<int>> m_selectedIndex;
    sodium::cell<std::optional<T>> m_currentItem;
};

template<class T>
SQComboBox<T>::SQComboBox(const QVector<Item> &items, QWidget *parent)
    : SQWidgetBase<QComboBox>(parent)
    , m_items(items)
    , m_selectedIndex({}, this, [this](std::optional<int> i) { setIndex(i); })
    , m_currentItem(std::nullopt)
{
    for (const Item &item : items)
        addItem(item.displayName);

    connect(this, &QComboBox::currentIndexChanged, this, [this](int i) {
        m_selectedIndex.setUserValue(i);
    });

    m_currentItem = m_selectedIndex.value().map([this](std::optional<int> i) -> std::optional<T> {
        if (i && *i >= 0 && *i < count())
            return std::make_optional(m_items.at(*i).value);
        return std::nullopt;
    });
}

template<class T>
void SQComboBox<T>::setIndex(std::optional<int> i)
{
    if (i && *i >= 0 && *i < count())
        setCurrentIndex(*i);
}

template<class T>
const sodium::cell<std::optional<T>> &SQComboBox<T>::currentItem() const
{
    return m_currentItem;
}
