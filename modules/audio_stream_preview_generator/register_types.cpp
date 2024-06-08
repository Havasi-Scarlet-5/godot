#include "register_types.h"

#include "audio_stream_preview.h"
#include "core/object/class_db.h"

static AudioStreamPreviewGenerator *preview_generator_ptr = NULL;

void initialize_audio_stream_preview_generator_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	preview_generator_ptr = memnew(AudioStreamPreviewGenerator);
	GDREGISTER_CLASS(AudioStreamPreviewGenerator);
	GDREGISTER_CLASS(AudioStreamPreview);
	Engine::get_singleton()->add_singleton(Engine::Singleton("AudioStreamPreviewGenerator", AudioStreamPreviewGenerator::get_singleton()));
}

void uninitialize_audio_stream_preview_generator_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	memdelete(preview_generator_ptr);
}
