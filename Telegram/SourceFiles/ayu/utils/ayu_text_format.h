/*
This file is part of AyuGram Desktop.
*/
#pragma once

#include "ui/text/text_entity.h"

namespace AyuUi {

[[nodiscard]] QString TextWithEntitiesToMarkdown(const TextWithEntities &text);

} // namespace AyuUi
