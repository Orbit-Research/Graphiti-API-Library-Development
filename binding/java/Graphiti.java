package binding.java;

public class Graphiti {
    static { System.loadLibrary("Graphiti"); }
    private long nativeHandle;

    public static class PinInfo {
        public int rowID;
        public int columnID;
        public int height;
        public int blinkRate;
    }

    public static class DrawEvent {
        public int length;
        public PinInfo[] pins;
    }

    public Graphiti() { nativeHandle = graphiti_create(); }
    public void close() { graphiti_destroy(nativeHandle); }

    public native long graphiti_create();
    public native long graphiti_createWithConnection(long connection);
    public native void graphiti_destroy(long handle);
    public native void setConnection(long handle, long connection);
    public native boolean startUpVCP(long handle, String port, boolean key, boolean touch);
    public native void shutDownVCP(long handle, boolean key, boolean touch);
    public native String getNextOutputEvent(long handle);
    public native int[] getDisplayStatusEvent(long handle);
    public native String[] getNextKeyEvent(long handle);
    public native DrawEvent getNextDrawEvent(long handle);  // custom struct wrapper
}

