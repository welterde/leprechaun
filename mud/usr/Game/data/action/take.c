# include <game/action.h>
# include <game/description.h>
# include <game/message.h>
# include <game/thing.h>

inherit LIB_ACTION;
inherit UTIL_DESCRIPTION;
inherit UTIL_MESSAGE;

int item_;

static void create(object LIB_ITEM *items)
{
    item_ = object_number(items[0]);
}

void perform(object LIB_CREATURE actor)
{
    object LIB_ROOM room;
    object LIB_ITEM item;

    room = environment(actor);
    if (!room) {
        tell_object(actor, "You are in the void.");
        return;
    }

    item = find_object(item_);
    if (!item || (object LIB_ROOM) environment(item) != room) {
        tell_object(actor, "That is not here.");
        return;
    }

    if (item->move(actor)) {
        tell_object(actor, "You take " + definite_description(item, actor)
                    + ".");
        tell_audience(actor, definite_description(actor) + " takes "
                      + indefinite_description(item) + ".");
    } else {
        tell_object(actor, "You cannot take "
                    + definite_description(item, actor) + ".");
    }
}
