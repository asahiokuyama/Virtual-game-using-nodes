# Virtual-game-using-nodes

NODEを使って選択肢を与える仮想的なゲーム。

今回の場合は宝探しのようなゲーム。

// 宝探しゲーム
// プレイヤーは、宝物を探して進む。
// 各ノードでup,right,leftを選択して進む(u/r/lで選択)
// 進む回数が多いほど、つまり宝物を探すのに時間がかかればかかるほど、スコアが溜まって行ってしまう。
// スコアは低ければ低いほど良いものとする。
// 途中、やめたくなったらfを押せばゲームをその時点で終了することが出来る。
// 宝物の在り処は、NODE１からleft->leftの位置にある。
// 選択肢にある数字はデバッグ用の現在地(ノード番号)
