/*
 * The MIT License (MIT)
 *
 *Copyright (c) 2014 Gustavo Franco
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include <NewPing.h>

// sonar
#define PING_PIN       12
#define MAX_DISTANCE   100
// engine one
#define EN_A           7
#define IN_1           6
#define IN_2           5
// engine two
#define EN_B           2
#define IN_3           4
#define IN_4           3

NewPing sonar(PING_PIN, PING_PIN, MAX_DISTANCE);

bool isEnemyAhead(void) {
  delay(50);

  return (sonar.ping() / US_ROUNDTRIP_CM) != 0;
}

void rotate(void) {
 digitalWrite(IN_1, HIGH);
 digitalWrite(IN_2, LOW);

 digitalWrite(IN_3, HIGH);
 digitalWrite(IN_4, LOW);
}

void moveForward(void) {
 digitalWrite(IN_1, HIGH);
 digitalWrite(IN_2, LOW);

 digitalWrite(IN_3, LOW);
 digitalWrite(IN_4, HIGH);
}

void moveBackward(void) {
 digitalWrite(IN_1, LOW);
 digitalWrite(IN_2, HIGH);

 digitalWrite(IN_3, HIGH);
 digitalWrite(IN_4, LOW);
}

void setup(void) {
 pinMode(EN_A, OUTPUT);
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);

 pinMode(EN_B, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT);

 digitalWrite(EN_A, HIGH);
 digitalWrite(EN_B, HIGH);
}

void loop(void) {
  rotate();
  while (!isEnemyAhead()) {}

  moveForward();
  while (isEnemyAhead()) {}
}
