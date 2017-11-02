#ifndef NODOC_H
#define NODOC_H

#define TEMPLATE_NODOC template <class KEY, class GIVEN>

TEMPLATE_NODOC
class NoDoc
{
public:
    NoDoc(KEY,GIVEN);
    NoDoc(KEY);
    NoDoc();
    KEY getChave();
    GIVEN getDado();
    void setChave(KEY);
    void setDado(GIVEN);
private:
    KEY chave;
    GIVEN dado;
};
#endif // NODOC_H
