# Report of challenge 2

### 事例1: eコマースプラットフォーム

ある開発チームは、eコマースプラットフォームの開発に取り組んでいます。このプラットフォームでは売り手が商品を出品し、顧客は気に入った商品をカートに入れて購入できます。さらに、このプラットフォームではショッピングサービスをパーソナライズするために、さまざまなタイプのターゲット顧客を頻繁に分析する必要があります。

この開発チームは継続的インテグレーションを導入し、コードをコミットするたびにテストを実行できるようにしました。しかし、顧客分析をスムーズに進めながら、現在稼働中のWebサイトに新機能やアップデートを効率的にデプロイすることには課題を抱えています。

#### 提案するソリューション

* 新機能・アップデートの継続的デプロイの仕組みを導入する
* 取得した顧客情報を自動で分析するパイプラインを構築する
* 顧客分析を止めないように、ブルー/グリーンデプロイを導入してダウンタイムを減らす

### 事例2: 旅行メディアのWebサイト

ある開発チームは旅行メディアのWebサイトを開発しています。このWebサイトでは、複数のライターがコンテンツ管理システム (CMS) を使って記事の作成、更新、削除を同時に行います。このチームはバージョン管理を活用しており、Webサイトのコード用のリモートリポジトリをセットアップ済みです。しかし、コードを手動のみでレビューしているため、コードの不整合、コンフリクト、公開の遅れにつながることもあります。

#### 提案するソリューション

* 継続的インテグレーションの仕組みを導入し、自動ビルド・テストを各々のマージ前に実行することで不整合を回避
* ブランチ戦略を立て、プルリクエストを利用し、コンフリクトを事前に検知する
* 継続的デリバリーの仕組みを導入し、自動ビルド・テストに通ったコードを自動でデリバリーできる状態にする
