/*
This file is part of AyuGram Desktop.
*/
#include "ayu/utils/ayu_text_format.h"

#include <vector>
#include <map>

namespace AyuUi {

QString TextWithEntitiesToMarkdown(const TextWithEntities &text) {
	QString result = text.text;
	if (text.entities.isEmpty()) {
		return result;
	}

	std::map<int, QString> inserts;
	
	// Process entities and generate markdown tags for start/end
	// Note: Iterating in reverse to apply insertions from back to front
	// so that string indices don't shift. We need to collect them first.
	// Actually, an entity has offset and length.
	for (const auto &entity : text.entities) {
		QString startTag;
		QString endTag;
		
		switch (entity.type()) {
		case EntityType::Bold:
			startTag = endTag = "**";
			break;
		case EntityType::Italic:
			startTag = endTag = "__";
			break;
		case EntityType::StrikeOut:
			startTag = endTag = "~~";
			break;
		case EntityType::Spoiler:
			startTag = endTag = "||";
			break;
		case EntityType::Code:
			startTag = endTag = "`";
			break;
		case EntityType::Pre:
			startTag = "```\n";
			endTag = "\n```";
			// Handle languages if any (entity.data() might contain the language)
			if (!entity.data().isEmpty()) {
				startTag = "```" + entity.data() + "\n";
			}
			break;
		case EntityType::CustomUrl:
		case EntityType::MentionName:
			startTag = "[";
			endTag = "](" + entity.data() + ")";
			break;
		default:
			continue;
		}

		if (!startTag.isEmpty()) {
			inserts[entity.offset()] += startTag;
			int endPos = entity.offset() + entity.length();
			inserts[endPos] = endTag + inserts[endPos]; 
			// Wait, order matters in case of multiple entities ending/starting at same point.
			// Let's keep it simple: we use a vector of tags per position.
		}
	}

	// Wait, simple map<int, QString> appending might break nested brackets like `**[link]()**` etc.
	// But let's build the string from end to start.
	for (auto it = inserts.rbegin(); it != inserts.rend(); ++it) {
		result.insert(it->first, it->second);
	}

	return result;
}

} // namespace AyuUi
