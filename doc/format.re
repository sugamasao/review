= ReVIEW フォーマット

ReVIEW フォーマットの文法について解説します。ReVIEW
フォーマットは ASCII の EWB を基本としながら、一部に
RD や各種 Wiki の文法をとりいれて簡素化しています。

== 段落

段落の間は英語の段落のように一行空けます。ただし、組版に
まわすときは前処理して 1 段落を 1 行に変更してあります。

=== [例]

//emlist{
  だんらくだんらく〜〜〜
  この行も同じ段落

  次の段落〜〜〜
//}

== 章・節・項・段

章・節・項・段のキャプションは「=」「==」「===」「====」
です。5 レベル以上は使えません。

=== [例]

//emlist{
  = 章のキャプション

  == 節のキャプション

  === 項のキャプション

  ==== 段のキャプション
//}

== コラムなど

節や項の文法に [column] を追加するとコラムのキャプションに
なります。

=== [例]

//emlist{
  ===[column] コンパイラコンパイラ
//}

このとき、「=」と「[column]」は必ずくっつけて書かなければ
なりません。空白があってもいけません。

== 箇条書き

箇条書き (HTML で言う ul) は「*」で表現します。
ネストはしません。

=== [例]

//emlist{
  * 第一の項目
  * 第二の項目
  * 第三の項目
//}

== 番号付き箇条書き

番号付きの箇条書き (HTML で言う ol) は「1. 〜」「2. 〜」
「3. 〜」で示します。ネストはしません。

=== [例]

//emlist{
  1. 第一の条件
  2. 第二の条件
  3. 第三の条件
//}

== 用語リスト

用語リスト (HTML で言う dl) は「:」を使って示します。

=== [例]

//emlist{
    : Alpha
        DEC の作っていた RISC CPU。
        浮動小数点数演算が速い。
    : POWER
        IBM とモトローラが共同製作した RISC CPU。
        派生として POWER PC がある。
    : SPARC
        Sun が作っている RISC CPU。
        CPU 数を増やすのが得意。
//}

頭の「:」それ自体はテキストではないので注意してください。

また、リスト内でも後述するインライン命令は有効です。

== ソースコードなどのリスト

ソースコードリストにはキャプションの付くリストとキャプ
ションの付かないリストがあります。キャプション付きリス
トは「//list[識別子][キャプション]{ 〜 //}」で、
キャプションなしリストは「//emlist{ 〜 //}」です。

=== [例1]

//emlist{
  //list[main][main()]{    ←「main」が識別子で「main()」がキャプション
  int
  main(int argc, char **argv)
  {
      puts("OK");
      return 0;
  }
  //}
//}

=== [例2]

//emlist{
  //emlist{
  printf("hello");
  //}
//}

ブロック内でも後述するインライン命令は有効です。

また本文中で「リスト X を見てください」のようにリストを指定
する場合は、//list で指定した識別子を使って「@@<list>{main}」
と表記します。

== ソースコードの引用

ソースコードを引用する場合、ファイル名が必要です。

=== [例]

//emlist{
  //source[/hello/world.rb]{
   puts "hello world!"
  //}
//}

== 行番号付きキャプションありリスト

キャプションありのリスト(list)で自動的に行番号がつきます。

=== [例]

//emlist{
  //listnum[hello][ハローワールド]{
   puts "hello world!"
  //}
//}

参照方法はlistと変わりません。

=== [例]

//emlist{
  ..は@@<list>{hello}をみてください。
//}

== 行番号付きキャプションなしリスト

キャプション無しのリスト(emlist)で自動的に行番号がつきます。

=== [例]

//emlist{
  //emlistnum{
   puts "hello world!"
  //}
//}

== 本文中でのソースコード引用

本文中でソースコードを引用して記述します。

=== [例]

//emlist{
  @@<code>{p = obj.ref_cnt}
//}

== コマンドラインのキャプチャ

コマンドラインの操作を示すときは //cmd{ 〜 //} を使います。

=== [例]

//emlist{
  //cmd{
  $ ls /
  //}
//}

ブロック内でも後述するインライン命令は有効です。

== 図

図は //image{ 〜 //} で指定します。執筆中はアスキーアートで
代替しているため、ダミーのアスキーアートが入っていることがあり
ます。この部分は、組版時には単に無視してください。

=== [例]

//emlist{
  //image[unixhistory][UNIX系OSの簡単な系譜]{
	      System V 系列
	      +----------- SVr4 --> 各種商用UNIX（Solaris, AIX, HP-UX, ...）
  V1 --> V6 --|
	      +--------- 4.4BSD --> FreeBSD, NetBSD, OpenBSD, ...
	      BSD 系列

		    --------------> Linux
  //}
//}

また本文中で「図 X を見てください」のように図を指定する場合は、
 //image で指定した識別子を用いて「@@<img>{unixhistory}」と
記述します。//image と @@<img> でつづりが違うので注意してください。

== 表

表は //table[識別子][キャプション]{ 〜 //} です。ヘッダと内容を
分ける罫線は「------」で書き込んであります。

カラム間は任意個数のタブで区切ります。また、カラム先頭の「.」は削
除されるので、カラムの先頭文字が「.」の場合は「.」をもう一つ余計に
付けてください。例えば「.」という内容のカラムは「..」と書きます。
また、空のカラムは「.」と書けます。

=== [例]

//emlist{

  //table[envvars][重要な環境変数]{
  名前            意味
  -------------------------------------------------------------
  PATH            コマンドの存在するディレクトリ
  TERM            使っている端末の種類。linux・kterm・vt100など
  LANG            ユーザのデフォルトロケール。日本語ならja_JP.eucJPやja_JP.utf8
  LOGNAME         ユーザのログイン名
  TEMP            一時ファイルを置くディレクトリ。/tmpなど
  PAGER           manなどで起動するテキスト閲覧プログラム。lessなど
  EDITOR          デフォルトエディタ。viやemacsなど
  MANPATH         manのソースを置いているディレクトリ
  DISPLAY         X Window Systemのデフォルトディスプレイ
  //}
//}

本文中で「表 X を見てください」のように表を指定する場合は
@<table>{envvars} という表記を使います。

表内でも後述するインライン命令は有効です。

== 引用

引用は「//quote{ 〜 //}」を使って記述します。

=== [例]

//emlist{
    //quote{
    百聞は一見に如かず。
    //}
//}

引用内でも後述するインライン命令は有効です。
また、いまのところ引用内で別のブロック構文を使うことはできません。

== 脚注

脚注は「//footnote」を使って記述します。

=== [例]

//emlist{
  パッケージは本書のサポートサイトから入手できます@@<fn>{site}。
  各自ダウンロードしてインストールしておいてください。
  //footnote[site][本書のサポートサイト： http://i.loveruby.net/ja/stdcompiler ]
//}

本文中の「@@<fn>{site}」は脚注番号に置換され、「本書のサポート
サイト……」という文は実際の脚注に変換されます。

== 参考文献の定義

参考文献は同一ディレクトリ内の bib.re に定義します。
  //bibpaper[site][キャプション]{..コメント..}
コメントが無い場合も定義可能です。
  //bibpaper[site][キャプション]

=== [例]

//emlist{
  //bibpaper[lins][Lins, 1991]{
  Refael D. Lins. A shared memory architecture for parallel study of
  algorithums for cyclic reference_counting. Technical Report 92,
  Computing Laboratory, The University of Kent at Canterbury , August
  1991
  //}
//}

本文中で参考文献を参照したい場合は次のようにしてください。

=== [例]

//emlist{
  …という研究が知られています(@@<bib>{lins})
//}

== リード文

リード文は //read{ 〜 //} で指定します。lead でなく read
なのは、ASCII の EWB が「read」を使っていたからです。

=== [例]

//emlist{
  //read{
  本章ではまずこの本の概要について話し、
  次にLinuxでプログラムを作る方法を説明していきます。
  //}
//}

== 空白制御

: //noindent
    段落冒頭のインデントなし

: //linebreak
    改行

: //pagebreak
    改ページ

== コメント

正式なタグでは伝達できない情報を記述するために //comment を使います。

=== [例]

//emlist{
  //comment[ここで 1 行あける]
//}

== その他の文法

ReVIEW は任意のブロックを追加可能なので、本によって専用ブロックを
使う場合があります。これまでに使った例を以下に示します。

: //prototype
    関数プロトタイプ。『ふつうのLinuxプログラミング』で使用。

: //type
    関数の型宣言。『ふつうのHaskellプログラミング』で使用。

== 段落中で使う文法 (インライン命令)

: @<list>{program}
    「リスト1.5」のような文字列に置換される。

: @<img>{unixhistory}
    「図1.3」のような文字列に置換される。

: @<table>{ascii}
    「表1.2」のような文字列に置換される。

: @<fn>{site}
    脚注番号に置換される。

: @<kw>{信任状, credential}
    キーワード。太字などにして強調してください。

: @<chap>{advanced}
    「第17章」のような、章番号を含むテキストに置換される。

: @<title>{advanced}
    その章の章題に置換される。

: @<chapref>{advanced}
    『第17章「さらに進んだ話題」』のように、章番号とタイトル
    を含むテキストに置換される。

: @<bou>{ふさわしい}
    傍点。

: @<ruby>{直截, ちょくせつ}
    ルビ。

: @<ami>{重点ポイント}
    文字に対するアミかけ。

: @<b>{どうしても}
    太字。

== 著者用タグ (プリプロセッサ命令)

これまでに説明したタグはすべて最終段階まで残り、見ために
影響を与えます。それに対して以下のタグは著者が使うための
専用タグであり、最終段階ではすべて消されてしまいます。

: #@#
    コメント。この行には何を書いても無視される。

: #@warn(...)
    警告メッセージ。プリプロセス時にメッセージが出力される。

: #@require, #@provide
    キーワードの依存関係を宣言する。

: #@mapfile(ファイル名) 〜 #@end
    ファイルの内容をその場に展開する。

: #@maprange(ファイル名, 範囲名) 〜 #@end
    ファイル内の範囲をその場に展開する。

: #@mapoutput(コマンド) 〜 #@end
    コマンドを実行して、その出力結果を展開する。

== HTMLのレイアウト機能

CHAPSファイルが置かれているディレクトリに layouts/layout.erb
を置くとその html を ERB で評価します。

=== [例1]

//emlist{
  <html>
    <head>
      <title><%= title %></title>
    </head>
//}

=== [例2]

//emlist{
  <html>
    <head>
      <title><%= title %></title>
    </head>
    <body>
      <%= body %>
      <hr/>
    </body>
  </html>
//}

== 部タイトル取得(目次生成機能)

PART ファイルに定義してください。
PART ファイルは CHAPS の部わけと対応しています。

=== [例]

//emlist{
CHAPS:
  intro.re
  start.re
  end.re

PART:
  (序章なので空行)
  はじまりの部
  おわりの部
//}

== リンク

Web ハイパーリンクを記述するには、リンクに @@<href>、アンカーに //label
を使います。リンクの書式は @@<href>{URL, 文字表現} で、「, 文字表現」を
省略すると URL がそのまま使われます。URL 中に , を使いたいときには、\,
と表記してください。

[例]
//emlist{
 @@<href>{http://github.com/, GitHub}
 @@<href>{http://www.google.com/}
 @@<href>{#point1, ドキュメント内ポイント}
 @@<href>{chap1.html#point1, ドキュメント内ポイント}
 //label[point1]
//}
