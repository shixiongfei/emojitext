#pragma once

#include "varchar.h"
#include <map>
#include <string>

// https://unicode.org/emoji/charts/full-emoji-list.html

typedef enum Emotion {
    EMOTION_NONE,

    FACE_SMILING,
    FACE_AFFECTION,
    FACE_TONGUE,
    FACE_HAND,
    FACE_NEUTRAL_SKEPTICAL,
    FACE_SLEEPY,
    FACE_UNWELL,
    FACE_HAT,
    FACE_GLASSES,
    FACE_CONCERNED,
    FACE_NEGATIVE,
    FACE_COSTUME,

    EMOTION_MAX
} Emotion;

typedef struct EmojiData {
    std::string name;
    Emotion emotion;
} EmojiData;

class Emoji {
public:
    Emoji(VarChar ch);
    virtual ~Emoji(void);

    const EmojiData & data(void) const;

public:
    static bool isEmoji(const VarChar &ch);

private:
    VarChar m_varchar;

private:
    static std::map<ucs4_t, EmojiData> s_emojiList;
};
