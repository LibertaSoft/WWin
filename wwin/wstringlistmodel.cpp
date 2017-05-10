#include "wstringlistmodel.h"

/**
 * @brief WStringListModel::WStringListModel Конструктор с инициализацией базового класса модели
 * @param parent - родитель
 */
WStringListModel::WStringListModel(WObject *parent)
    : WAbstractItemModel(parent)
{}

/**
 * @brief WStringListModel::WStringListModel Конструктор с инициализацией базового класса модели
 * и установкой данных.
 * @param strings - данные, список строк.
 * @param parent - родитель
 */
WStringListModel::WStringListModel(const WStringList &strings, WObject *parent)
    : WAbstractItemModel(parent)
{
    this->setStringList(strings);
}

WStringListModel::~WStringListModel()
{
    this->dataChanhed({0,0}, {_stringList.size(),1});
}

/**
 * @brief WStringListModel::setStringList Установить список строк в модель
 * @param strings - список строк
 */
void WStringListModel::setStringList(const WStringList &strings)
{
    _stringList = strings;
    this->dataChanhed({0,0}, {strings.size(),1});
}

/**
 * @brief WStringListModel::stringList получить список строк из модели
 * @return
 */
WStringList WStringListModel::stringList() const
{
    return _stringList;
}

/**
 * @brief WStringListModel::data Получить данные по индексу в модели
 * @param index - индекс в модели
 * @return данный по запрошенному индексу
 */
WVariant WStringListModel::data(WModelIndex index)
{
    if( (_stringList.size() < index.row) || (_stringList.size() > index.row) ) {
        return _stringList[index.row];
    } else {
        return WVariant(L"NULL");
    }
}

/**
 * @brief WStringListModel::setData установить данные в модель по указанному индексу
 * @param index - индекс, позиция в модели
 * @param data - данные
 * @return true
 */
bool WStringListModel::setData(WModelIndex index, WVariant data)
{
    if( index.row < 0 || index.row > this->rowCount() ){
        _stringList.push_back(data);
        this->dataChanhed({_stringList.size()-1,0}, {_stringList.size(),1});
    } else {
        _stringList[index.row] = data;
        this->dataChanhed({index.row,0}, {index.row+1,1});
    }
    return true;
}

/**
 * @brief WStringListModel::removeRow Удалить данные из модели по индексу.
 * @param index - индекс удаляемой записи
 * @return
 */
bool WStringListModel::removeRow(WModelIndex index)
{
    _stringList.erase(_stringList.begin() + index.row, _stringList.begin() + index.row + 1);
    return true;
}

/**
 * @brief WStringListModel::rowCount получить количество строк
 * @return количество строк
 */
int WStringListModel::rowCount(WModelIndex) const
{
    return _stringList.size();
}

/**
 * @brief WStringListModel::columnCount получить количество столбцов
 * @return количество столбцов
 */
int WStringListModel::columnCount(WModelIndex) const
{
    return 0; /// \todo Может тут должен быть 1? 1 столбец то полюбому есть
}

