int cnt;

void setup() {
  Serial.begin(9600); //9600 = 통신속도 -> Serial 통신으로 연결되는 상대방이 지정한 통신속도가 일치해야함
  cnt = 0; //초기화
}

void loop() {
  Serial.println(cnt); //cnt값을 시리얼 모니터에 출력
  cnt += 1 //1씩 증가
  delay(1000); //1초 딜레이
}
