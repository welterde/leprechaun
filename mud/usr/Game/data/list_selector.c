# include <game/actor.h>
# include <game/identifiable.h>
# include <game/selector.h>

inherit LIB_SELECTOR;

object LIB_SELECTOR *sels_;

static void create(object LIB_SELECTOR *sels)
{
    sels_ = sels;
}

object LIB_IDENTIFIABLE *select(object LIB_IDENTIFIABLE *objs,
                                object LIB_ACTOR actor)
{
    object LIB_IDENTIFIABLE *res;
    int i, size;

    res = ({ });
    size = sizeof(sels_);
    for (i = 0; i < size; ++i) {
        res |= sels_[i]->select(objs, actor);
    }
    return res;
}