#define STB_IMAGE_IMPLEMENTATION
#include "RenderManager.h"

int main() {

	RenderManager::instance().init();
	RenderManager::instance().runRenderLoop();

	return 0;
}
