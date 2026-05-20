// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#include <dlfcn.h>
#include <X11/Xlib.h>
#include <hime-im-client.h>

namespace HimeHelper {
namespace {

void (*hime_im_client_close)(HIME_client_handle *handle);
void (*hime_im_client_focus_in)(HIME_client_handle *handle);
void (*hime_im_client_focus_out)(HIME_client_handle *handle);
void (*hime_im_client_focus_out2)(HIME_client_handle *handle, char **rstr);
int (*hime_im_client_forward_key_press)(
	HIME_client_handle *handle,
	const KeySym key,
	const uint32_t state,
	char **rstr);
int (*hime_im_client_forward_key_release)(
	HIME_client_handle *handle,
	const KeySym key,
	const uint32_t state,
	char **rstr);
int (*hime_im_client_get_preedit)(
	HIME_client_handle *handle,
	char **str,
	HIME_PREEDIT_ATTR att[],
	int *cursor,
	int *sub_comp_len);
HIME_client_handle *(*hime_im_client_open)(Display *display);
void (*hime_im_client_reset)(HIME_client_handle *handle);
void (*hime_im_client_set_cursor_location)(
	HIME_client_handle *handle,
	const int x,
	const int y);
void (*hime_im_client_set_flags)(
	HIME_client_handle *handle,
	const int flags,
	int *ret_flags);
void (*hime_im_client_set_client_window)(
	HIME_client_handle *handle,
	const Window win);
void (*hime_im_client_set_window)(HIME_client_handle *handle, Window win);

template <typename Function>
inline bool LoadSymbol(void *lib, const char *name, Function &func) {
	func = reinterpret_cast<Function>(dlsym(lib, name));
	return (func != nullptr);
}

bool Resolve() {
	static const auto loaded = [&] {
		void *lib = dlopen("libhime-im-client.so.1", RTLD_LAZY | RTLD_NODELETE);
		if (!lib) {
			return false;
		}
		return LoadSymbol(lib, "hime_im_client_close", hime_im_client_close)
			&& LoadSymbol(lib, "hime_im_client_focus_in", hime_im_client_focus_in)
			&& LoadSymbol(lib, "hime_im_client_focus_out", hime_im_client_focus_out)
			&& LoadSymbol(lib, "hime_im_client_focus_out2", hime_im_client_focus_out2)
			&& LoadSymbol(lib, "hime_im_client_forward_key_press", hime_im_client_forward_key_press)
			&& LoadSymbol(lib, "hime_im_client_forward_key_release", hime_im_client_forward_key_release)
			&& LoadSymbol(lib, "hime_im_client_get_preedit", hime_im_client_get_preedit)
			&& LoadSymbol(lib, "hime_im_client_open", hime_im_client_open)
			&& LoadSymbol(lib, "hime_im_client_reset", hime_im_client_reset)
			&& LoadSymbol(lib, "hime_im_client_set_cursor_location", hime_im_client_set_cursor_location)
			&& LoadSymbol(lib, "hime_im_client_set_flags", hime_im_client_set_flags)
			&& (LoadSymbol(lib, "hime_im_client_set_client_window", hime_im_client_set_client_window)
				|| LoadSymbol(lib, "hime_im_client_set_window", hime_im_client_set_window));
	}();
	return loaded;
}

} // namespace
} // namespace HimeHelper

void hime_im_client_close(HIME_client_handle *handle) {
	HimeHelper::Resolve();
	HimeHelper::hime_im_client_close(handle);
}

void hime_im_client_focus_in(HIME_client_handle *handle) {
	HimeHelper::Resolve();
	HimeHelper::hime_im_client_focus_in(handle);
}

void hime_im_client_focus_out(HIME_client_handle *handle) {
	HimeHelper::Resolve();
	HimeHelper::hime_im_client_focus_out(handle);
}

void hime_im_client_focus_out2(HIME_client_handle *handle, char **rstr) {
	HimeHelper::Resolve();
	HimeHelper::hime_im_client_focus_out2(handle, rstr);
}

int hime_im_client_forward_key_press(
	HIME_client_handle *handle,
	const KeySym key,
	const uint32_t state,
	char **rstr) {
	HimeHelper::Resolve();
	return HimeHelper::hime_im_client_forward_key_press(
		handle,
		key,
		state,
		rstr);
}

int hime_im_client_forward_key_release(
	HIME_client_handle *handle,
	const KeySym key,
	const uint32_t state,
	char **rstr) {
	HimeHelper::Resolve();
	return HimeHelper::hime_im_client_forward_key_release(
		handle,
		key,
		state,
		rstr);
}

int hime_im_client_get_preedit(
	HIME_client_handle *handle,
	char **str,
	HIME_PREEDIT_ATTR att[],
	int *cursor,
	int *sub_comp_len) {
	HimeHelper::Resolve();
	return HimeHelper::hime_im_client_get_preedit(
		handle,
		str,
		att,
		cursor,
		sub_comp_len);
}

HIME_client_handle *hime_im_client_open(Display *display) {
	HimeHelper::Resolve();
	return HimeHelper::hime_im_client_open(display);
}

void hime_im_client_reset(HIME_client_handle *handle) {
	HimeHelper::Resolve();
	HimeHelper::hime_im_client_reset(handle);
}

void hime_im_client_set_cursor_location(
	HIME_client_handle *handle,
	const int x,
	const int y) {
	HimeHelper::Resolve();
	HimeHelper::hime_im_client_set_cursor_location(
		handle,
		x,
		y);
}

void hime_im_client_set_flags(
	HIME_client_handle *handle,
	const int flags,
	int *ret_flags) {
	HimeHelper::Resolve();
	HimeHelper::hime_im_client_set_flags(
		handle,
		flags,
		ret_flags);
}

void hime_im_client_set_client_window(
	HIME_client_handle *handle,
	const Window win) {
	HimeHelper::Resolve();
	HimeHelper::hime_im_client_set_client_window(handle, win);
}

void hime_im_client_set_window(HIME_client_handle *handle, Window win) {
	HimeHelper::Resolve();
	HimeHelper::hime_im_client_set_window(handle, win);
}
