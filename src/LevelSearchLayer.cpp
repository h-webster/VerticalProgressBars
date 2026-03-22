#include <Geode/Geode.hpp>

using namespace geode::prelude;
#include <Geode/modify/PlayLayer.hpp>
class $modify(myPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }
        return true;
    }
    void updateProgressbar() {
        PlayLayer::updateProgressbar();    
        
        auto progressBarParent = this->getChildByID("progress-bar");
        if (!progressBarParent) return;
        auto progressBar = static_cast<CCSprite*>(progressBarParent->getChildren()->objectAtIndex(0));
        if (!progressBar) return;

        const float maxProgressWidth = 206.f;
        const float maxProgressHeight = 8.f;
        
        auto currentRect = progressBar->getTextureRect();
        float progress = currentRect.size.width / maxProgressWidth;
        float adjustedProgress = 1.52 + (progress) * (6.62-1.52);
        progressBar->setTextureRect(CCRect(0, 0, maxProgressWidth, adjustedProgress)); 
     
    } 
};