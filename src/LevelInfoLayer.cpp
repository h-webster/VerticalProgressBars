#include <Geode/Geode.hpp>
using namespace geode::prelude;
#include <Geode/modify/LevelInfoLayer.hpp>
class $modify(myLevelInfoLayer, LevelInfoLayer) {
    bool init(GJGameLevel* level, bool challenge) {
        if (!LevelInfoLayer::init(level, challenge)) return false;
        
        auto normalBarParent = this->getChildByID("normal-mode-bar");
        if (!normalBarParent) return true;
        auto normalBar = static_cast<CCSprite*>(normalBarParent->getChildren()->objectAtIndex(0));
        if (!normalBar) return true;
        
        auto practiceBarParent = this->getChildByID("practice-mode-bar");
        if (!practiceBarParent) return true;
        auto practiceBar = static_cast<CCSprite*>(practiceBarParent->getChildren()->objectAtIndex(0));
        if (!practiceBar) return true;

        const float maxProgressWidth = 340.f;
        const float maxProgressHeight = 20.f;
        const float minProgressHeight = 0.f;
        
        auto normalRect = normalBar->getTextureRect();
        auto practiceRect = practiceBar->getTextureRect();

        float normalProgress = normalRect.size.width / maxProgressWidth;
        float adjustedNormalProgress = minProgressHeight + (normalProgress) * (maxProgressHeight - minProgressHeight);
        
        float practiceProgress = practiceRect.size.width / maxProgressWidth; 
        float adjustedPracticeProgress = minProgressHeight + (practiceProgress) * (maxProgressHeight - minProgressHeight);

        normalBar->setAnchorPoint(CCPoint(0, 0));
        normalBar->setFlipY(true);
        normalBar->setPosition(CCPoint(0, 0));
        normalBar->setTextureRect(CCRect(0, 0, maxProgressWidth, adjustedNormalProgress)); 

        practiceBar->setAnchorPoint(CCPoint(0, 0));
        practiceBar->setFlipY(true);
        practiceBar->setPosition(CCPoint(0, 0));
        practiceBar->setTextureRect(CCRect(0, 0, maxProgressWidth, adjustedPracticeProgress)); 

        return true;
    }
};