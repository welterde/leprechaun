/*
 * - prefers light armor
 * - prefers wild animals as mounts, like elks and deers
 * - prefers hunting weapons such as bows, spears, and knives
 * - strong against goblins
 */

# include <game/attribute.h>
# include <game/race.h>

inherit LIB_RACE;

static void create()
{
    ::create();
    set_name("Elf");
    add_noun("elf", "elves");

    set_attribute_shares(([ STRENGTH_ATTRIBUTE:    0.6,
                            SPEED_ATTRIBUTE:       1.2,
                            PERCEPTION_ATTRIBUTE:  1.1,
                            CHARISMA_ATTRIBUTE:    1.1 ]));
}
