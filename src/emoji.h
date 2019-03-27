#pragma once

#include "varchar.h"
#include <map>
#include <string>

// https://unicode.org/emoji/charts/full-emoji-list.html

typedef enum EmojiType {
    EMOTION_NONE,

    // Smileys & Emotion
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
    CAT_FACE,
    MONKEY_FACE,
    EMOTION,

    // People & Body

    // Component

    // Animals & Nature

    // Food & Drink

    // Travel & Places

    // Activities

    // Objects

    // Symbols

    // Flags

    // 

    EMOTION_MAX
} EmojiType;

typedef struct EmojiData {
    std::string name;
    EmojiType emotion;
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
