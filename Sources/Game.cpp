#include "Game.hpp"


// TODO: 砲台の位置を画面左に、ターゲットの位置を画面右に移動させる。(A) HW16A096 白永 滉
// TODO: 雲の位置を左から右に動かす。見えなくなったら左端に戻す。(B) HW16A096 白永 滉
// TODO: 砲台を青い壁に沿って上下に動かす。(C) HW15A062　菊地 龍大
// TODO: 弾のスピードを速くし、弾が画面右端を通り越したら再度発射可能にする。(D) HW15A062　菊地 龍大
// TODO: スコアのサイズを大きくする。(E)//HW15A213 山本 裕生
// TODO: スコアを100点ずつ加算するようにし、5桁の表示に変える。(F)//HW15A213 山本 裕生
// TODO: PlayBGM()関数を使って、BGMを再生する。(G)//HW16A007 池田 悠斗
// TODO: PlaySE()関数を使って、弾の発射時とターゲットに当たった時にSEを再生する。(H) HW16A007 池田 悠斗


Vector2 cloudPos;       //!< 雲の位置
Vector2 cannonPos;      //!< 砲台の位置
Vector2 cannonInitPos;  //!< 砲台の初期位置(実装：HW15A062　菊地龍大)
Vector2 bulletPos;      //!< 弾の位置
Rect    targetRect;     //!< ターゲットの矩形
int     score;          //!< スコア


// ゲーム開始時に呼ばれる関数です。
void Start()
{
    cloudPos = Vector2(-380, 100);  //雲の初期位置を少し左にずらしました
    cannonPos = Vector2(-250, -150);//砲台を左に動かしました(HW16A096 白永 滉)
    cannonInitPos = cannonPos;// 砲台の初期位置を取得(実装：HW15A062　菊地龍大)
    targetRect = Rect(250, -140, 40, 40); //ターゲットを右に動かしました(HW16A096 白永 滉)
    bulletPos.x = -999;
    score = 0;
    PlayBGM("bgm_maoudamashii_8bit07.mp3");     //hw16a007
}

// 1/60秒ごとに呼ばれる関数です。モデルの更新と画面の描画を行います。
void Update()
{
    // 弾の発射
    if (bulletPos.x <= -999 && Input::GetKeyDown(KeyMask::Space)) {
        bulletPos = cannonPos + Vector2(50, 10);
        PlaySound("se_maoudamashii_explosion03.mp3");
    }

    // 弾の移動
    if (bulletPos.x > -999) {
        bulletPos.x += 640 * Time::deltaTime;// 弾の速度を変更(実装：HW15A062　菊地龍大)

        // ターゲットと弾の当たり判定
        Rect bulletRect(bulletPos, Vector2(32, 20));
        if (targetRect.Overlaps(bulletRect)) {
            score += 100;         // スコアの加算 //HW15A213 山本 裕生
            bulletPos.x = -999; // 弾を発射可能な状態に戻す
            PlaySound("se_maoudamashii_system20.mp3");
        }
        // 弾が画面外に出ると再発射できるように(実装：HW15A062　菊地龍大)
        if(bulletPos.x > Screen::size().x / 2.0f){
            bulletPos.x = -999; // 弾を発射可能な状態に戻す
        }
    }

    // 背景の描画
    Clear(Color::cyan);
    FillRect(Rect(-320, -240, 640, 100), Color::green);

    // 雲の描画
    cloudPos.x += 100.0f*Time::deltaTime;
    if(cloudPos.x > Screen::size().x / 2){
        cloudPos.x = -380;      //雲を左から右へ動かして画面外に出ると初期位置に戻るようにしました
    }
    DrawImage("cloud1.png", cloudPos);
    

    // 弾の描画
    if (bulletPos.x > -999) {
        DrawImage("bullet.png", bulletPos);
    }

    // 砲台の描画
    FillRect(Rect(cannonInitPos.x-10, -140, 20, 100), Color::blue);// 描画位置を砲台の初期位置に(実装：HW15A062　菊地龍大)
    cannonPos.y = -160 + 100 * Mathf::PingPong(Time::time, 1.0f);// 砲台を自動的に上下移動させる(実装：HW15A062　菊地龍大)
    DrawImage("cannon.png", cannonPos);

    // ターゲットの描画
    FillRect(targetRect, Color::red);

    // スコアの描画
    SetFont("nicoca_v1.ttf", 70.0f);//HW15A213 山本 裕生
    DrawText(FormatString("%05d", score), Vector2(-319, 180), Color::black);//HW15A213 山本 裕生
    DrawText(FormatString("%05d", score), Vector2(-320, 181), Color::white);//HW15A213 山本 裕生
}

