### Video demo
Link: https://youtu.be/hrA4inFmNaA

### Mô tả chương trình

Đây là một chương trình sử dụng **ESP32** để điều khiển và hiển thị trạng thái của **hai loại cảm biến**:  
- Cảm biến **hồng ngoại**
- Cảm biến **va chạm**  

Thông tin được hiển thị trên **màn hình LCD 16x2**, và người dùng có thể **chọn chế độ hoạt động** thông qua **hai nút nhấn vật lý**.


### Chức năng chính

- **Hiển thị menu chọn chế độ** trên LCD:  
  Khi khởi động, màn hình sẽ hiển thị dòng `"Choose mode"` để người dùng lựa chọn.

- **Chuyển chế độ bằng nút nhấn**:
  - Nhấn nút **1**: vào chế độ **IR Mode**
  - Nhấn nút **2**: vào chế độ **Touch Mode**

- **Trong mỗi chế độ hoạt động**:
  - Dòng đầu tiên trên LCD hiển thị tên chế độ.
  - Dòng thứ hai hiển thị trạng thái cảm biến:
    - `State: ON` nếu phát hiện tín hiệu.
    - `State: OFF` nếu không có tín hiệu.

- **Quay lại menu chọn chế độ**:
  - Trong bất kỳ chế độ nào, người dùng có thể nhấn nút để quay lại màn hình chọn chế độ ban đầu.


### Phần cứng sử dụng

| Thiết bị            | Ghi chú                            |
|---------------------|------------------------------------|
| Màn hình LCD 16x2   | Giao tiếp ở chế độ 4-bit           |
| Cảm biến hổng ngoại | Dùng để phát hiện vật cản          |
| Cảm biến va chạm    | Dùng để phát hiện thao tác chạm    |
| 2 nút nhấn vật lý   | Dùng để chọn chế độ hoạt động      |
| ESP32               | Vi điều khiển chính                |

