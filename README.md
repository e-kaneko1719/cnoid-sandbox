# cnoid-sandbox

ビルド時のコマンド
`$ colcon build --symlink-install --cmake-args -DBUILD_AGX_DYNAMICS_PLUGIN=ON -DBUILD_AGX_BODYEXTENSION_PLUGIN=ON -DBUILD_WRS2018=ON -DBUILD_RTF_TEST_PLANT=ON -DBUILD_HAIRO_WORLD_PLUGIN=ON -DBUILD_CNOID_SANDBOX=ON`

---
**内容物について**

model/
Door.body

・rtf-test-plantモデル内のドアのみを取り出したもの

![Screenshot from 2024-07-25 15-28-15](https://github.com/user-attachments/assets/d445d4e5-50b4-4bb5-9685-ac41606ec2e3)


BreakableJointDoor*.body
BreakableJointDoor2.body

・Doorモデルの関節部にAGXBreakableJointを適用し、力を加えると扉が外れるようにしたモデル
・力が加わると破壊される。ツールを使わずともダブルアームのハンドで触れて押し続けた場合も破壊されてしまう。


BreakableJointDoor3.body

・ドアフレームとドアに隙間を設けて奥まったところにヒンジを設置。ダブルアームのハンドは入らないが、尖ったツールで押すと破壊可能。

![Screenshot from 2024-07-25 15-33-41](https://github.com/user-attachments/assets/c2ba4465-20a8-4314-a219-4ae5b86c693e)



FireCabinet_BoxOnly.body

・箱部分を取り出したもの

![Screenshot from 2024-07-25 15-28-49](https://github.com/user-attachments/assets/9fd78f15-559b-4bde-ad29-080eb5b95496)


FireCabinet_Door.body

・奥の壁を取り除きドア状にしたもの
・AizuSpiderが通れる程度のサイズ

![Screenshot from 2024-07-23 09-30-25](https://github.com/user-attachments/assets/fc34938a-25db-432c-bab1-eac202c554c5)

TankPlatformをまとめたもの
![TankPlatform](https://github.com/user-attachments/assets/854c8806-18e5-427b-aac3-d99c4ed8c219)
![TankPlatformNoHandrails](https://github.com/user-attachments/assets/646ac63f-9aad-4216-b7ce-b546250d3415)

押し続けると倒れる破壊可能なポール
[BreakableJointPole.webm](https://github.com/user-attachments/assets/dcd5608c-b04d-4fe2-b291-5b463516435b)

押し続けると倒れる元の位置に復帰可能なポール
[MagneticJointPole.webm](https://github.com/user-attachments/assets/7545f2d9-e3b6-4582-b848-30bc09483770)
