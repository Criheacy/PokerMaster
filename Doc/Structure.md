# PokerMaster 设计文档

### CardClass

- 用于存储卡牌的花色、数字

- 每一张卡牌是一个单独的实例，全局存在54*2张永久实例
- 属性：
  - Value：花色，数字
  - Owner：所属玩家
  - IsFlipped, IsActive, IsSelected, IsFaded
  - ZIndex：叠放层次
  - Transform：继承于Object类，负责变换属性
  - Animation：卡牌动画
- Public方法：
  - 摸牌（被摸入某玩家手中）
  - 打出（自玩家手中打出至弃牌堆）
  - 整理（自弃牌堆整理至牌堆中央）



### AnimationClass

- 控制物体的动画属性，通过直接改变Transform改变动画

- 需要挂在Object类上，且Object类上有Transform属性
- 计算是异步的，每次调用Transform.GetPos的时候会更新属性

