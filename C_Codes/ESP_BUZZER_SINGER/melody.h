#ifndef MELODY_H
#define MELODY_H

#include <stdint.h>
#include <stddef.h>

// ---------------------------------------------------------------------------
// Note frequencies in Hz (equal temperament, A4 = 440 Hz, rounded).
// Number = octave. "S" = sharp (C#, D#, ...).
// NOTE_REST (0) means silence.
// ---------------------------------------------------------------------------
#define NOTE_REST  0

#define NOTE_C4   262
#define NOTE_CS4  277
#define NOTE_D4   294
#define NOTE_DS4  311
#define NOTE_E4   330
#define NOTE_F4   349
#define NOTE_FS4  370
#define NOTE_G4   392
#define NOTE_GS4  415
#define NOTE_A4   440
#define NOTE_AS4  466
#define NOTE_B4   494

#define NOTE_C5   523
#define NOTE_CS5  554
#define NOTE_D5   587
#define NOTE_DS5  622
#define NOTE_E5   659
#define NOTE_F5   698
#define NOTE_FS5  740
#define NOTE_G5   784
#define NOTE_GS5  831
#define NOTE_A5   880
#define NOTE_AS5  932
#define NOTE_B5   988

// ---------------------------------------------------------------------------
// Timing: change BEAT_MS to make the whole song faster or slower.
// ---------------------------------------------------------------------------
#define BEAT_MS      400     // length of one beat in milliseconds
#define NOTE_GAP_MS  20      // short silence after every note, so equal notes don't blur together

// ---------------------------------------------------------------------------
// One entry of the song: which note, and for how long.
// ---------------------------------------------------------------------------
typedef struct {
    uint16_t freq_hz;        // note frequency, or NOTE_REST
    uint16_t duration_ms;    // how long the note lasts
} note_t;

// The song. Edit this table to change what is played.
static const note_t melody[] = {

    // Happy birthday to you
    {NOTE_G4, BEAT_MS},
    {NOTE_G4, BEAT_MS},
    {NOTE_A4, 2 * BEAT_MS},
    {NOTE_G4, 2 * BEAT_MS},
    {NOTE_C5, 2 * BEAT_MS},
    {NOTE_B4, 3 * BEAT_MS},

    // Happy birthday to you
    {NOTE_G4, BEAT_MS},
    {NOTE_G4, BEAT_MS},
    {NOTE_A4, 2 * BEAT_MS},
    {NOTE_G4, 2 * BEAT_MS},
    {NOTE_D5, 2 * BEAT_MS},
    {NOTE_C5, 3 * BEAT_MS},

    // Happy birthday dear ...
    {NOTE_G4, BEAT_MS},
    {NOTE_G4, BEAT_MS},
    {NOTE_G5, 2 * BEAT_MS},
    {NOTE_E5, 2 * BEAT_MS},
    {NOTE_C5, 2 * BEAT_MS},
    {NOTE_B4, 2 * BEAT_MS},
    {NOTE_A4, 3 * BEAT_MS},

    // Happy birthday to you
    {NOTE_F5, BEAT_MS},
    {NOTE_F5, BEAT_MS},
    {NOTE_E5, 2 * BEAT_MS},
    {NOTE_C5, 2 * BEAT_MS},
    {NOTE_D5, 2 * BEAT_MS},
    {NOTE_C5, 3 * BEAT_MS}
};


#define MELODY_LENGTH  (sizeof melody / sizeof melody[0])

#endif // MELODY_H
