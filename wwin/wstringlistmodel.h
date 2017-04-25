#ifndef WSTRINGLISTMODEL_H
#define WSTRINGLISTMODEL_H

#include <vector>

#include "wwin/wstring.h"
#include "wwin/wobject.h"
#include "wwin/wabstractitemmodel.h"

/**
 * @brief WStringList если понадобится отдельно - нужно вынести в отдельный класс
 */
typedef std::vector<WString> WStringList;

/**
 * @brief WStringListModel Модель со списком строк.
 * Является реализацией модели на системе Model-View реализованной в WWin
 */
class WStringListModel : public WAbstractItemModel
{
private:
    WStringList _stringList; /// < список строк

public:
    WStringListModel(WObject *parent = nullptr);
    WStringListModel(const WStringList &strings, WObject *parent = nullptr);

    void setStringList(const WStringList& strings);
    WStringList stringList() const;

    virtual WVariant data(WModelIndex index) override;
    virtual bool setData(WModelIndex index, WVariant data);
    virtual bool removeRow(WModelIndex index);

    virtual int rowCount(WModelIndex parent = {0,0}) const override;
    virtual int columnCount(WModelIndex parent = {0,0}) const override;
};

#endif // WSTRINGLISTMODEL_H
