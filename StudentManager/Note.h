#ifndef NOTE_H
#define NOTE_H
class Note {
private:
    int studentId;
    float value;
public:
    Note(int studentId, float value)
        : studentId(studentId), value(value) {}

    int getStudentId() const {
        return studentId;
    }
    float getValue() const {
        return value;
    }
    void setValue(float newValue) {
        value = newValue;
    }
};
#endif