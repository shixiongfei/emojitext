#include "emoji.h"

Emoji::Emoji(VarChar ch)
    : m_varchar(ch)
{
}

Emoji::~Emoji(void)
{
}

const EmojiData & Emoji::data(void) const
{
    static const EmojiData empty = { "none", EMOTION_NONE };

    auto iter = Emoji::s_emojiList.find(m_varchar.toUCS4());

    if (iter == Emoji::s_emojiList.end())
        return empty;

    return iter->second;
}

bool Emoji::isEmoji(const VarChar & ch)
{
    return Emoji::s_emojiList.find(ch.toUCS4()) != Emoji::s_emojiList.end();
}

std::map<ucs4_t, EmojiData> Emoji::s_emojiList = {
    { 0x1F600, { "grinning face",                   FACE_SMILING } },
    { 0x1F603, { "grinning face with big eyes",     FACE_SMILING } },
    { 0x1F604, { "grinning face with smiling eyes", FACE_SMILING } },
    { 0x1F601, { "beaming face with smiling eyes",  FACE_SMILING } },
    { 0x1F606, { "grinning squinting face",         FACE_SMILING } },
    { 0x1F605, { "grinning face with sweat",        FACE_SMILING } },
    { 0x1F923, { "rolling on the floor laughing",   FACE_SMILING } },
    { 0x1F602, { "face with tears of joy",          FACE_SMILING } },
    { 0x1F642, { "slightly smiling face",           FACE_SMILING } },
    { 0x1F643, { "upside - down face",              FACE_SMILING } },
    { 0x1F609, { "winking face",                    FACE_SMILING } },
    { 0x1F60A, { "smiling face with smiling eyes",  FACE_SMILING } },
    { 0x1F607, { "smiling face with halo",          FACE_SMILING } },

    { 0x1F970, { "smiling face with hearts",        FACE_AFFECTION } },
    { 0x1F60D, { "smiling face with heart - eyes",  FACE_AFFECTION } },
    { 0x1F929, { "star - struck",                   FACE_AFFECTION } },
    { 0x1F618, { "face blowing a kiss",             FACE_AFFECTION } },
    { 0x1F617, { "kissing face",                    FACE_AFFECTION } },
    {  0x263A, { "smiling face",                    FACE_AFFECTION } },
    { 0x1F61A, { "kissing face with closed eyes",   FACE_AFFECTION } },
    { 0x1F619, { "kissing face with smiling eyes",  FACE_AFFECTION } },

    { 0x1F60B, { "face savoring food",              FACE_TONGUE } },
    { 0x1F61B, { "face with tongue",                FACE_TONGUE } },
    { 0x1F61C, { "winking face with tongue",        FACE_TONGUE } },
    { 0x1F92A, { "zany face",                       FACE_TONGUE } },
    { 0x1F61D, { "squinting face with tongue",      FACE_TONGUE } },
    { 0x1F911, { "money - mouth face",              FACE_TONGUE } },

    { 0x1F917, { "hugging face",                    FACE_HAND } },
    { 0x1F92D, { "face with hand over mouth",       FACE_HAND } },
    { 0x1F92B, { "shushing face",                   FACE_HAND } },
    { 0x1F914, { "thinking face",                   FACE_HAND } },

    { 0x1F910, { "zipper - mouth face",             FACE_NEUTRAL_SKEPTICAL } },
    { 0x1F928, { "face with raised eyebrow",        FACE_NEUTRAL_SKEPTICAL } },
    { 0x1F610, { "neutral face",                    FACE_NEUTRAL_SKEPTICAL } },
    { 0x1F611, { "expressionless face",             FACE_NEUTRAL_SKEPTICAL } },
    { 0x1F636, { "face without mouth",              FACE_NEUTRAL_SKEPTICAL } },
    { 0x1F60F, { "smirking face",                   FACE_NEUTRAL_SKEPTICAL } },
    { 0x1F612, { "unamused face",                   FACE_NEUTRAL_SKEPTICAL } },
    { 0x1F644, { "face with rolling eyes",          FACE_NEUTRAL_SKEPTICAL } },
    { 0x1F62C, { "grimacing face",                  FACE_NEUTRAL_SKEPTICAL } },
    { 0x1F925, { "lying face",                      FACE_NEUTRAL_SKEPTICAL } },

    { 0x1F60C, { "relieved face",                   FACE_SLEEPY } },
    { 0x1F614, { "pensive face",                    FACE_SLEEPY } },
    { 0x1F62A, { "sleepy face",                     FACE_SLEEPY } },
    { 0x1F924, { "drooling face",                   FACE_SLEEPY } },
    { 0x1F634, { "sleeping face",                   FACE_SLEEPY } },

    { 0x1F637, { "face with medical mask",          FACE_UNWELL } },
    { 0x1F912, { "face with thermometer",           FACE_UNWELL } },
    { 0x1F915, { "face with head - bandage",        FACE_UNWELL } },
    { 0x1F922, { "nauseated face",                  FACE_UNWELL } },
    { 0x1F92E, { "face vomiting",                   FACE_UNWELL } },
    { 0x1F927, { "sneezing face",                   FACE_UNWELL } },
    { 0x1F975, { "hot face",                        FACE_UNWELL } },
    { 0x1F976, { "cold face",                       FACE_UNWELL } },
    { 0x1F974, { "woozy face",                      FACE_UNWELL } },
    { 0x1F635, { "dizzy face",                      FACE_UNWELL } },
    { 0x1F92F, { "exploding head",                  FACE_UNWELL } },

    { 0x1F920, { "cowboy hat face",                 FACE_HAT } },
    { 0x1F973, { "partying face",                   FACE_HAT } },

    { 0x1F60E, { "smiling face with sunglasses",    FACE_GLASSES } },
    { 0x1F913, { "nerd face",                       FACE_GLASSES } },
    { 0x1F9D0, { "face with monocle",               FACE_GLASSES } },

    { 0x1F615, { "confused face",                   FACE_CONCERNED } },
    { 0x1F61F, { "worried face",                    FACE_CONCERNED } },
    { 0x1F641, { "slightly frowning face",          FACE_CONCERNED } },
    {  0x2639, { "frowning face",                   FACE_CONCERNED } },
    { 0x1F62E, { "face with open mouth",            FACE_CONCERNED } },
    { 0x1F62F, { "hushed face",                     FACE_CONCERNED } },
    { 0x1F632, { "astonished face",                 FACE_CONCERNED } },
    { 0x1F633, { "flushed face",                    FACE_CONCERNED } },
    { 0x1F97A, { "pleading face",                   FACE_CONCERNED } },
    { 0x1F626, { "frowning face with open mouth",   FACE_CONCERNED } },
    { 0x1F627, { "anguished face",                  FACE_CONCERNED } },
    { 0x1F628, { "fearful face",                    FACE_CONCERNED } },
    { 0x1F630, { "anxious face with sweat",         FACE_CONCERNED } },
    { 0x1F625, { "sad but relieved face",           FACE_CONCERNED } },
    { 0x1F622, { "crying face",                     FACE_CONCERNED } },
    { 0x1F62D, { "loudly crying face",              FACE_CONCERNED } },
    { 0x1F631, { "face screaming in fear",          FACE_CONCERNED } },
    { 0x1F616, { "confounded face",                 FACE_CONCERNED } },
    { 0x1F623, { "persevering face",                FACE_CONCERNED } },
    { 0x1F61E, { "disappointed face",               FACE_CONCERNED } },
    { 0x1F613, { "downcast face with sweat",        FACE_CONCERNED } },
    { 0x1F629, { "weary face",                      FACE_CONCERNED } },
    { 0x1F62B, { "tired face",                      FACE_CONCERNED } },
    { 0x1F971, { "yawning face",                    FACE_CONCERNED } },

    { 0x1F624, { "face with steam from nose",       FACE_NEGATIVE } },
    { 0x1F621, { "pouting face",                    FACE_NEGATIVE } },
    { 0x1F620, { "angry face",                      FACE_NEGATIVE } },
    { 0x1F92C, { "face with symbols on mouth",      FACE_NEGATIVE } },
    { 0x1F608, { "smiling face with horns",         FACE_NEGATIVE } },
    { 0x1F47F, { "angry face with horns",           FACE_NEGATIVE } },
    { 0x1F480, { "skull",                           FACE_NEGATIVE } },
    {  0x2620, { "skull and crossbones",            FACE_NEGATIVE } },

    { 0x1F4A9, { "pile of poo",                     FACE_COSTUME } },
    { 0x1F921, { "clown face",                      FACE_COSTUME } },
    { 0x1F479, { "ogre",                            FACE_COSTUME } },
    { 0x1F47A, { "goblin",                          FACE_COSTUME } },
    { 0x1F47B, { "ghost",                           FACE_COSTUME } },
    { 0x1F47D, { "alien",                           FACE_COSTUME } },
    { 0x1F47E, { "alien monster",                   FACE_COSTUME } },
    { 0x1F916, { "robot",                           FACE_COSTUME } },

    { 0x1F63A, { "grinning cat",                    CAT_FACE } },
    { 0x1F638, { "grinning cat with smiling eyes",  CAT_FACE } },
    { 0x1F639, { "cat with tears of joy",           CAT_FACE } },
    { 0x1F63B, { "smiling cat with heart - eyes",   CAT_FACE } },
    { 0x1F63C, { "cat with wry smile",              CAT_FACE } },
    { 0x1F63D, { "kissing cat",                     CAT_FACE } },
    { 0x1F640, { "weary cat",                       CAT_FACE } },
    { 0x1F63F, { "crying cat",                      CAT_FACE } },
    { 0x1F63E, { "pouting cat",                     CAT_FACE } },

    { 0x1F648, { "see - no - evil monkey",          MONKEY_FACE } },
    { 0x1F649, { "hear - no - evil monkey",         MONKEY_FACE } },
    { 0x1F64A, { "speak - no - evil monkey",        MONKEY_FACE } },

    { 0x1F48B, { "kiss mark",                       EMOTION } },
    { 0x1F48C, { "love letter",                     EMOTION } },
    { 0x1F498, { "heart with arrow",                EMOTION } },
    { 0x1F49D, { "heart with ribbon",               EMOTION } },
    { 0x1F496, { "sparkling heart",                 EMOTION } },
    { 0x1F497, { "growing heart",                   EMOTION } },
    { 0x1F493, { "beating heart",                   EMOTION } },
    { 0x1F49E, { "revolving hearts",                EMOTION } },
    { 0x1F495, { "two hearts",                      EMOTION } },
    { 0x1F49F, { "heart decoration",                EMOTION } },
    {  0x2763, { "heart exclamation",               EMOTION } },
    { 0x1F494, { "broken heart",                    EMOTION } },
    {  0x2764, { "red heart",                       EMOTION } },
    { 0x1F9E1, { "orange heart",                    EMOTION } },
    { 0x1F49B, { "yellow heart",                    EMOTION } },
    { 0x1F49A, { "green heart",                     EMOTION } },
    { 0x1F499, { "blue heart",                      EMOTION } },
    { 0x1F49C, { "purple heart",                    EMOTION } },
    { 0x1F90E, { "brown heart",                     EMOTION } },
    { 0x1F5A4, { "black heart",                     EMOTION } },
    { 0x1F90D, { "white heart",                     EMOTION } },
    { 0x1F4AF, { "hundred points",                  EMOTION } },
    { 0x1F4A2, { "anger symbol",                    EMOTION } },
    { 0x1F4A5, { "collision",                       EMOTION } },
    { 0x1F4AB, { "dizzy",                           EMOTION } },
    { 0x1F4A6, { "sweat droplets",                  EMOTION } },
    { 0x1F4A8, { "dashing away",                    EMOTION } },
    { 0x1F573, { "hole",                            EMOTION } },
    { 0x1F4A3, { "bomb",                            EMOTION } },
    { 0x1F4AC, { "speech balloon",                  EMOTION } },
    { 0x1F441, { "eye in speech bubble",            EMOTION } },
    {  0xFE0F, { "eye in speech bubble",            EMOTION } },
    {  0x200D, { "eye in speech bubble",            EMOTION } },
    { 0x1F5E8, { "eye in speech bubble",            EMOTION } },
    {  0xFE0F, { "eye in speech bubble",            EMOTION } },
    { 0x1F5E8, { "left speech bubble",              EMOTION } },
    { 0x1F5EF, { "right anger bubble",              EMOTION } },
    { 0x1F4AD, { "thought balloon",                 EMOTION } },
    { 0x1F4A4, { "zzz",                             EMOTION } },

};
